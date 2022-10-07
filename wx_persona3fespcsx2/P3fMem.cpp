#include "P3fMem.h"
#include <iostream>
#include <iostream>
#if defined(_WIN32)

//the following code was taken from the original persona3fes trainer
HWND hwind;
BOOL CALLBACK GetHwindCallback(HWND hwnd, LPARAM lParam) {
	static TCHAR buffer[50];
	GetWindowText(hwnd, buffer, 50);
	if (_tcsstr(buffer, TEXT("PCSX2"))) {
		hwind = hwnd;
		return FALSE;
	}

	return TRUE;
}
#endif
void P3fMem::WriteValue(LONG pokeAddress, int value, int bytesize) {
#if defined (_WIN32)
	//get the handle by opening a process using the process id
	HANDLE pHandle = OpenProcess(PROCESS_ALL_ACCESS, 0, pcsxpid);

	//write to memory using the process handle
	switch (bytesize) {
	case 1:
		WriteProcessMemory(pHandle, (LPVOID)pokeAddress, &value, sizeof(bool), NULL);
		break;
	case 2:
		WriteProcessMemory(pHandle, (LPVOID)pokeAddress, &value, sizeof(short int), NULL);
		break;
	case 4:
		WriteProcessMemory(pHandle, (LPVOID)pokeAddress, &value, sizeof(long), NULL);
		break;
	
	}
	CloseHandle(pHandle);

#endif
#if defined(__linux__)
	//similar thing in linux but more difficult really
	//borrowed code snippet from Chris Wellons at url:  https://nullprogram.com/blog/2016/09/03/
	//writing to process memory is like writing to a file
	//need char array to put file name
	char file[64];

	//would look like a char[] = /proc/someid/mem
	sprintf(file, "/proc/%ld/mem",(long)pcsxpid);

	//we open the file as file descriptor fd for short
	int fd = open(file, O_RDWR);

	//we have to tell OS that we are some kind of debugger to allow us to write to the memory
	ptrace(PTRACE_ATTACH, pcsxpid,0,0);

	//we wait for the process to stop running then we write. 
	waitpid(pcsxpid,NULL,0);
	switch (bytesize) {
	case 1:
		pwrite(fd, (void*)&value, sizeof(bool),pokeAddress);
		break;
	case 2:
		pwrite(fd, (void*)&value, sizeof(short int),pokeAddress);
		break;
	case 4:
		pwrite(fd, (void*)&value, sizeof(long),pokeAddress);
		break;
	
	}
	//we detach from the process
	ptrace(PTRACE_DETACH, pcsxpid, 0, 0);

	//then we close the file descriptor
	close(fd);
#endif
}

bool P3fMem::SetPcsx2() {
#if defined (_WIN32)
	//enumare processes for each one call the 
	EnumWindows(GetHwindCallback, NULL);
	GetWindowThreadProcessId(hwind, &pcsxpid);	
	bool success = GetWindowThreadProcessId(FindWindow(NULL, TEXT("PCSX2")), &pcsxpid);

	//if we found it then we can continue
	if (hwind != NULL) {
		return true;
	}
	
#endif
#ifdef __linux__
	char line[10];
	_IO_FILE * command = popen("pidof PCSX2","r");
	fgets(line,10,command);
	pcsxpid = strtoul(line,NULL,10);
	pclose(command);
	std::cout << "testing if this will run" <<std::endl;
	if(pcsxpid > -1){
		return false;
		std::cout << pcsxpid << std::endl;
	}
	else{
		std::cout << pcsxpid << std::endl;
		return true;		
	}
#endif	
	//return false if we made it this far
	return false;
}
int P3fMem::SetItemAmount(LONG itemname, int amount)
{
	//try to avoid a mistake so check for memory out of bounds
	if ((itemname < P3fMem::Medicine || itemname > P3fMem::All_Seeing_Eye) 
		|| (amount < 0 || amount > 99)) {//value should not be out of bounds
		return -1;
	}
	//example: WriteValue(P3fMem::Medicine, amount, 2);
	WriteValue(itemname, amount, 2);
	return 0;
}
int P3fMem::SetMainCharacterLevel(int value)
{
	if (value < 0 || value > 99) {
		return -1;
	}
	WriteValue(P3fMem::Mc_Level, value, 2);
	return 0;
}
int P3fMem::SetMainCharacterHP(int value)
{
	if (value < 0 || value > 999) {
		return -1;
	}
	WriteValue(P3fMem::Mc_Current_HP, value, 2);
	return 0;
}
int P3fMem::SetMainCharacterMP(int value)
{
	if (value < 0 || value > 999) {
		return -1;
	}
	WriteValue(P3fMem::Mc_Current_MP, value, 2);
	return 0;
}

//realize that persona's memory location are well aligned
//seems there is an offset of 52d or 0x34h between personas
int P3fMem::SetPersonaLevel(int personaSlot, int value)
{
	if ((personaSlot > 8 || personaSlot < 0) && (value < 0 || value > 99)) {
		return -1;
	}
	WriteValue(P3fMem::Persona1_Level + (personaSlot * 0x34), value, 1);
	return 0;
}

int P3fMem::SetPersonaSt(int personaSlot, int value)
{
	if ((personaSlot > 8 || personaSlot < 0) && (value < 0 || value > 99)) {
		return -1;
	}
	WriteValue(P3fMem::Persona1_Str + (personaSlot * 0x34), value, 1);
	return 0;
}

int P3fMem::SetPersonaMa(int personaSlot, int value)
{
	if ((personaSlot > 8 || personaSlot < 0) && (value < 0 || value > 99)) {
		return -1;
	}
	WriteValue(P3fMem::Persona1_Mag + (personaSlot * 0x34), value, 1);
	return 0;
}

int P3fMem::SetPersonaEn(int personaSlot, int value)
{
	if ((personaSlot > 8 || personaSlot < 0) && (value < 0 || value > 99)) {
		return -1;
	}
	WriteValue(P3fMem::Persona1_En + (personaSlot * 0x34), value, 1);
	return 0;
}

int P3fMem::SetPersonaAg(int personaSlot, int value)
{
	if ((personaSlot > 8 || personaSlot < 0) && (value < 0 || value > 99)) {
		return -1;
	}
	WriteValue(P3fMem::Persona1_Ag + (personaSlot * 0x34), value, 1);
	return 0;
}

int P3fMem::SetPersonaLu(int personaSlot, int value)
{
	if ((personaSlot > 8 || personaSlot < 0) && (value < 0 || value > 99)) {
		return -1;
	}
	WriteValue(P3fMem::Persona1_Luc + (personaSlot * 0x34), value, 1);
	return 0;
}

int P3fMem::SetPersonaMagic1(int personaSlot, int value)
{
	if ((personaSlot > 8 || personaSlot < 0) && (value < 0 || value > 624)) {
		return -1;
	}
	WriteValue(P3fMem::Persona1_Magic1 + (personaSlot * 0x34), value, 2);
	return 0;
}

int P3fMem::SetPersonaMagic2(int personaSlot, int value)
{
	if ((personaSlot > 8 || personaSlot < 0) && (value < 0 || value > 624)) {
		return -1;
	}
	WriteValue(P3fMem::Persona1_Magic2 + (personaSlot * 0x34), value, 2);
	return 0;
}

int P3fMem::SetPersonaMagic3(int personaSlot, int value)
{
	if ((personaSlot > 8 || personaSlot < 0) && (value < 0 || value > 624)) {
		return -1;
	}
	WriteValue(P3fMem::Persona1_Magic3 + (personaSlot * 0x34), value, 2);
	return 0;
}

int P3fMem::SetPersonaMagic4(int personaSlot, int value)
{
	if ((personaSlot > 8 || personaSlot < 0) && (value < 0 || value > 624)) {
		return -1;
	}
	WriteValue(P3fMem::Persona1_Magic4 + (personaSlot * 0x34), value, 2);
	return 0;
}

int P3fMem::SetPersonaMagic5(int personaSlot, int value)
{
	if ((personaSlot > 8 || personaSlot < 0) && (value < 0 || value > 624)) {
		return -1;
	}
	WriteValue(P3fMem::Persona1_Magic5 + (personaSlot * 0x34), value, 2);
	return 0;
}

int P3fMem::SetPersonaMagic6(int personaSlot, int value)
{
	if ((personaSlot > 8 || personaSlot < 0) && (value < 0 || value > 624)) {
		return -1;
	}
	WriteValue(P3fMem::Persona1_Magic6 + (personaSlot * 0x34), value, 2);
	return 0;
}

int P3fMem::SetPersonaMagic7(int personaSlot, int value)
{
	if ((personaSlot > 8 || personaSlot < 0) && (value < 0 || value > 624)) {
		return -1;
	}
	WriteValue(P3fMem::Persona1_Magic7 + (personaSlot * 0x34), value, 2);
	return 0;
}

int P3fMem::SetPersonaMagic8(int personaSlot, int value)
{
	if ((personaSlot > 8 || personaSlot < 0) && (value < 0 || value > 624)) {
		return -1;
	}
	WriteValue(P3fMem::Persona1_Magic8 + (personaSlot * 0x34), value, 2);
	return 0;
}

int P3fMem::SetMainCharacterMood(int value)
{
	if (value < 0 || value > 3) {
		return -1;
	}
	WriteValue(P3fMem::Mc_Mood, value, 2);
	return 0;
}

int P3fMem::SetMainCharacterAcademics(int value)
{
	if (value < 0 || value > 260) {
		return -1;
	}
	WriteValue(P3fMem::Mc_Academics, value, 2);
	return 0;
}

int P3fMem::SetMainCharacterCharm(int value)
{
	if (value < 0 || value > 99) {
		return -1;
	}
	WriteValue(P3fMem::Mc_Charm, value, 2);
	return 0;
}

int P3fMem::SetMainCharacterCourage(int value)
{
	if (value < 0 || value > 99) {
		return -1;
	}
	WriteValue(P3fMem::Mc_Courage, value, 2);
	return 0;
}

int P3fMem::SetMainCharacterMoney(int value)
{
	if (value < 0 || value > 99999999) {
		return -1;
	}
	WriteValue(P3fMem::Mc_Money, value, 4);
	return 0;
}

int P3fMem::SetDesiredPersona(int personaSlot, int value)
{
	if ((personaSlot < 0 || personaSlot > 11) && (value < 0 || value > 191)) {
		return -1;
	}
	//as according to original writer 0 there is 21 dummy gap, so we skip it
	if (value > 169) {
		value = value + 21;
	}
	WriteValue(P3fMem::Persona1_Modifer + (personaSlot * 0x34), value, 2);
	return 0;
}
