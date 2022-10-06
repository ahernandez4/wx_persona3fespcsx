#include "wx_persona3fespcsx2.h"

//pcsx2 mem writer
P3fMem *p3fmemwriter;
extern void InitXmlResource();//defined in generated file
wxIMPLEMENT_APP(MyApp);//as per docs

bool MyApp::OnInit() {//as per docs
	
	MyFrame *myframe = new MyFrame();//as per docs
	p3fmemwriter = new P3fMem();
	bool did = p3fmemwriter->SetPcsx2();
	myframe->Show(true);

	if (!did) {
		wxLogMessage("ERROR: PCSX2 not found running\nMake sure it's running first");
		myframe->CleanUp();
		myframe->Close(true);
	}

	return true;//as per docs
}

MyFrame::MyFrame() {
	wxXmlResource::Get()->InitAllHandlers();
	//load resources //to use xrc file uncomment the line containing
	// ->Load("resources.xrc"); and commenout out the line that follows
	//wxXmlResource::Get()->Load("resource.xrc");
	InitXmlResource();

	//bind xrc resources to frame functions
	wxXmlResource::Get()->LoadFrame(this, (wxWindow*)NULL, "MyFrame1");
	
	//get wxWindow typed objecs using macro provided
	//find the object of the wxchoice using provided macro
	magicChoiceSlot1 = XRCCTRL(*this, "m_choice7", wxChoice);
	magicChoiceSlot2 = XRCCTRL(*this, "m_choice8", wxChoice);
	magicChoiceSlot3 = XRCCTRL(*this, "m_choice9", wxChoice);
	magicChoiceSlot4 = XRCCTRL(*this, "m_choice10", wxChoice);
	magicChoiceSlot5 = XRCCTRL(*this, "m_choice11", wxChoice);
	magicChoiceSlot6 = XRCCTRL(*this, "m_choice12", wxChoice);
	magicChoiceSlot7 = XRCCTRL(*this, "m_choice13", wxChoice);
	magicChoiceSlot8 = XRCCTRL(*this, "m_choice14", wxChoice);

	
	//find the persona slot choice
	slotChoice = XRCCTRL(*this, "m_SlotChoice", wxChoice);

	//choices defined as static
	magicChoices = wxArrayString(624, choices);
	
	//add the choices
	magicChoiceSlot1->Append(magicChoices);
	magicChoiceSlot2->Append(magicChoices);
	magicChoiceSlot3->Append(magicChoices);
	magicChoiceSlot4->Append(magicChoices);
	magicChoiceSlot5->Append(magicChoices);
	magicChoiceSlot6->Append(magicChoices);
	magicChoiceSlot7->Append(magicChoices);
	magicChoiceSlot8->Append(magicChoices);

	//find the persona choice field
	personaModifierChoice = XRCCTRL(*this, "m_choice2", wxChoice);

	//use persona array to create new wxarraystring
	personaChoices = wxArrayString(191, personas);

	//add personas
	personaModifierChoice->Append(personaChoices);

	//programmically add the list of inventory
	//first get the panel
	//basically get the panel that is already defined in the resouce file
	//then make a dataviewlist 
	wxPanel8 = XRCCTRL(*this, "m_panel8", wxPanel);
	listViewDvc = new wxDataViewListCtrl(wxPanel8, ID_DVCLIST,wxDefaultPosition,wxSize(250,500),wxDV_NO_HEADER);
	
	//add two columns. column 1 and 2. they have names, but I hide the names
	//cell_inert means can not edit and cell_editable meas able to edit
	listViewDvc->AppendTextColumn("item list", wxDATAVIEW_CELL_INERT, 200, wxALIGN_LEFT);
	listViewDvc->AppendTextColumn("item count", wxDATAVIEW_CELL_EDITABLE, 20, wxALIGN_CENTER);
	for (int count = 0; count < 222; count++) {
		
		//Can add a column data to dataviewlist as a vector
		wxVector<wxVariant> data;
		
		//get the string form the array
		data.push_back( (wxVariant) inventoryItems[count]);
		data.push_back(wxVariant("0"));
		
		//add the data
		listViewDvc->AppendItem(data);
	}
	
	//add a sizer so that basically list goes inside sizer and sizer inside panel
	panel8Sizer = new wxBoxSizer(wxHORIZONTAL);
	panel8Sizer->Add(listViewDvc, 0, wxEXPAND);
	wxPanel8->SetSizer(panel8Sizer);	

	//bind change to function using provided macro to find ids
	Bind(wxEVT_MENU, &MyFrame::OnExit, this, XRCID("m_menuItemExit"));
	Bind(wxEVT_SPINCTRL, &MyFrame::OnChangeHPSpinCtrl, this, XRCID("m_HPspinCtrl"));
	Bind(wxEVT_SPINCTRL, &MyFrame::OnChangeLevelSpinCtrl, this, XRCID("m_LvlspinCtrl"));
	Bind(wxEVT_SPINCTRL, &MyFrame::OnChangeMPSpinCtrl, this, XRCID("m_MPspinCtrl"));
	Bind(wxEVT_SPINCTRL, &MyFrame::OnChangeMoneySpinCtrl, this, XRCID("m_MoneySpinCtrl"));
	Bind(wxEVT_SPINCTRL, &MyFrame::OnChangeAcademicsSpinCtrl, this, XRCID("m_AcademicsSpinCtrl"));
	Bind(wxEVT_SPINCTRL, &MyFrame::OnChangeCharmSpingCtrl, this, XRCID("m_CharmSpinCtrl"));
	Bind(wxEVT_SPINCTRL, &MyFrame::OnChangeCourageSpinCtrl, this, XRCID("m_CourageSpinCtrl"));
	Bind(wxEVT_CHOICE, &MyFrame::OnChangeMoodChoice, this, XRCID("m_MoodChoice"));
	Bind(wxEVT_DATAVIEW_ITEM_VALUE_CHANGED, &MyFrame::OnValueChange, this, ID_DVCLIST);
	Bind(wxEVT_DATAVIEW_ITEM_EDITING_STARTED, &MyFrame::OnStartEdit, this, ID_DVCLIST);
	Bind(wxEVT_CHOICE, &MyFrame::OnChangeMagicSlot1Choice, this, XRCID("m_choice7"));
	Bind(wxEVT_CHOICE, &MyFrame::OnChangeMagicSlot2Choice, this, XRCID("m_choice8"));
	Bind(wxEVT_CHOICE, &MyFrame::OnChangeMagicSlot3Choice, this, XRCID("m_choice9"));
	Bind(wxEVT_CHOICE, &MyFrame::OnChangeMagicSlot4Choice, this, XRCID("m_choice10"));
	Bind(wxEVT_CHOICE, &MyFrame::OnChangeMagicSlot5Choice, this, XRCID("m_choice11"));
	Bind(wxEVT_CHOICE, &MyFrame::OnChangeMagicSlot6Choice, this, XRCID("m_choice12"));
	Bind(wxEVT_CHOICE, &MyFrame::OnChangeMagicSlot7Choice, this, XRCID("m_choice13"));
	Bind(wxEVT_CHOICE, &MyFrame::OnChangeMagicSlot8Choice, this, XRCID("m_choice14"));
	Bind(wxEVT_CHOICE, &MyFrame::OnChagePersonaModifierChoice, this, XRCID("m_choice2"));
	Bind(wxEVT_SPINCTRL, &MyFrame::OnChangePersonaLevelSpinCtrl, this, XRCID("m_PersonaLevelSpinCtrl"));
	Bind(wxEVT_SPINCTRL, &MyFrame::OnChangePersonaStSpinCtrl, this, XRCID("m_PersonaStSpinCtrl"));
	Bind(wxEVT_SPINCTRL, &MyFrame::OnChangePersonaMaSpinCtrl, this, XRCID("m_PersonaMaSpinCtrl"));
	Bind(wxEVT_SPINCTRL, &MyFrame::OnChangePersonaEnSpinCtrl, this, XRCID("m_PersonaEnSpinCtrl"));
	Bind(wxEVT_SPINCTRL, &MyFrame::OnChangePersonaAgSpinCtrl, this, XRCID("m_PersonaAgSpinCtrl"));
	Bind(wxEVT_SPINCTRL, &MyFrame::OnChangePersonaLuSpinCtrl, this, XRCID("m_PersonaLuSpinCtrl"));

}

void MyFrame::OnExit(wxCommandEvent& event) 
{
	
	this->CleanUp();
	Close(true);
	
}
//clean stuff not managed by wxwidgets
void MyFrame::CleanUp() {
	if (p3fmemwriter) {
		delete p3fmemwriter;
		p3fmemwriter = NULL;
	}
}
//previously we bound events to functions. here is one of those
//when the value inside MC_HP changes, this functions gets called
//use event to obtain the value then call our mem writer
void MyFrame::OnChangeHPSpinCtrl(wxSpinEvent &event) 
{
	int input = event.GetInt();
	p3fmemwriter->SetMainCharacterHP(input);
}
void MyFrame::OnChangeLevelSpinCtrl(wxSpinEvent & event)
{
	int input = event.GetInt();
	p3fmemwriter->SetMainCharacterLevel(input);
}
void MyFrame::OnChangeMPSpinCtrl(wxSpinEvent & event)
{
	int input = event.GetInt();
	p3fmemwriter->SetMainCharacterMP(input);
}
void MyFrame::OnChangeMoneySpinCtrl(wxSpinEvent & event)
{
	int input = event.GetInt();
	p3fmemwriter->SetMainCharacterMoney(input);
}
void MyFrame::OnChangeAcademicsSpinCtrl(wxSpinEvent & event)
{
	int input = event.GetInt();
	p3fmemwriter->SetMainCharacterAcademics(input);
}
void MyFrame::OnChangeCharmSpingCtrl(wxSpinEvent & event)
{
	int input = event.GetInt();
	p3fmemwriter->SetMainCharacterCharm(input);
}
void MyFrame::OnChangeCourageSpinCtrl(wxSpinEvent & event)
{
	int input = event.GetInt();
	p3fmemwriter->SetMainCharacterCourage(input);
}

//we bound this function when an item inside dataviewlist gets changed
void MyFrame::OnValueChange(wxDataViewEvent &event) 
{
	//which row to get the index
	int loc = listViewDvc->ItemToRow(event.GetItem());
	wxString myvalue = listViewDvc->GetTextValue(loc, 1);
	long longvalue = -1;
	//convert the string value to long
	myvalue.ToCLong(&longvalue);
	//check to see if the value is valid
	if (longvalue < 0) {
		//if we are here not a valid value
		listViewDvc->SetValue(prevalue, loc, 1);
	}
	else {
		int itemmem = P3fMem::Medicine;
		itemmem = itemmem + loc*2;//sorry. I got lazy here
		p3fmemwriter->SetItemAmount(itemmem, longvalue);
	}

}
//we bound this function when data inside dataview starts editing
void MyFrame::OnStartEdit(wxDataViewEvent &event) 
{
	//let's get the previous value just in case user tries to put characters
	int loc = listViewDvc->ItemToRow(event.GetItem());
	prevalue = listViewDvc->GetTextValue(loc, 1);
}
//functions gets called when value changes inside spinner
//use event to obtain the value then call our mem writer
void MyFrame::OnChangePersonaStSpinCtrl(wxSpinEvent & event)
{
	int input = event.GetInt();
	int selectedslot = slotChoice->GetCurrentSelection();
	p3fmemwriter->SetPersonaSt(selectedslot, input);
}
void MyFrame::OnChangePersonaMaSpinCtrl(wxSpinEvent & event)
{
	int input = event.GetInt();
	int selectedslot = slotChoice->GetCurrentSelection();
	p3fmemwriter->SetPersonaMa(selectedslot, input);
}
void MyFrame::OnChangePersonaEnSpinCtrl(wxSpinEvent & event)
{
	int input = event.GetInt();
	int selectedslot = slotChoice->GetCurrentSelection();
	p3fmemwriter->SetPersonaEn(selectedslot, input);
}
void MyFrame::OnChangePersonaAgSpinCtrl(wxSpinEvent & event)
{
	int input = event.GetInt();
	int selectedslot = slotChoice->GetCurrentSelection();
	p3fmemwriter->SetPersonaAg(selectedslot, input);
}
void MyFrame::OnChangePersonaLuSpinCtrl(wxSpinEvent & event)
{
	int input = event.GetInt();
	int selectedslot = slotChoice->GetCurrentSelection();
	p3fmemwriter->SetPersonaLu(selectedslot, input);
}
void MyFrame::OnChangeMoodChoice(wxCommandEvent &event) 
{
	int selectedmood = event.GetSelection();
	p3fmemwriter->SetMainCharacterMood(selectedmood);
	
}

//we bound this function when a choice is made in the drop down
void MyFrame::OnChangeMagicSlot1Choice(wxCommandEvent &event)
{
	int selectedindex = magicChoiceSlot1->GetCurrentSelection();
	int selectedslot = slotChoice->GetCurrentSelection();
	p3fmemwriter->SetPersonaMagic1(selectedslot, selectedindex);
}
void MyFrame::OnChangeMagicSlot2Choice(wxCommandEvent &event)
{
	int selectedindex = magicChoiceSlot2->GetCurrentSelection();
	int selectedslot = slotChoice->GetCurrentSelection();
	p3fmemwriter->SetPersonaMagic2(selectedslot, selectedindex);
}
void MyFrame::OnChangeMagicSlot3Choice(wxCommandEvent &event)
{
	int selectedindex = magicChoiceSlot3->GetCurrentSelection();
	int selectedslot = slotChoice->GetCurrentSelection();
	p3fmemwriter->SetPersonaMagic3(selectedslot, selectedindex);
}
void MyFrame::OnChangeMagicSlot4Choice(wxCommandEvent &event)
{
	int selectedindex = magicChoiceSlot4->GetCurrentSelection();
	int selectedslot = slotChoice->GetCurrentSelection();
	p3fmemwriter->SetPersonaMagic4(selectedslot, selectedindex);
}
void MyFrame::OnChangeMagicSlot5Choice(wxCommandEvent &event)
{
	int selectedindex = magicChoiceSlot5->GetCurrentSelection();
	int selectedslot = slotChoice->GetCurrentSelection();
	p3fmemwriter->SetPersonaMagic5(selectedslot, selectedindex);
}
void MyFrame::OnChangeMagicSlot6Choice(wxCommandEvent &event)
{
	int selectedindex = magicChoiceSlot6->GetCurrentSelection();
	int selectedslot = slotChoice->GetCurrentSelection();
	p3fmemwriter->SetPersonaMagic6(selectedslot, selectedindex);
}
void MyFrame::OnChangeMagicSlot7Choice(wxCommandEvent &event)
{
	int selectedindex = magicChoiceSlot7->GetCurrentSelection();
	int selectedslot = slotChoice->GetCurrentSelection();
	p3fmemwriter->SetPersonaMagic7(selectedslot, selectedindex);
}
void MyFrame::OnChangeMagicSlot8Choice(wxCommandEvent &event) {
	int selectedindex = magicChoiceSlot8->GetCurrentSelection();
	int selectedslot = slotChoice->GetCurrentSelection();
	p3fmemwriter->SetPersonaMagic8(selectedslot, selectedindex);
}
void MyFrame::OnChagePersonaModifierChoice(wxCommandEvent & event)
{
	int selectedindex = event.GetSelection();
	int selectedslot = slotChoice->GetCurrentSelection();
	p3fmemwriter->SetDesiredPersona(selectedslot,selectedindex);
}
void MyFrame::OnChangePersonaLevelSpinCtrl(wxSpinEvent & event) 
{
	int input = event.GetInt();
	int selectedslot = slotChoice->GetCurrentSelection();
	p3fmemwriter->SetPersonaLevel(selectedslot, input);
}
