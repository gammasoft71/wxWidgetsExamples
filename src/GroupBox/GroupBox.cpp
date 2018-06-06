#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "Panel example", wxDefaultPosition, wxSize(640, 480)) {
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxRadioBox* groupBox1 = new wxRadioBox(this->panel, wxID_ANY, "GroupBox 1", wxPoint(10, 10), wxSize(305, 440));
  wxRadioBox* groupBox2 = new wxRadioBox(this->panel, wxID_ANY, "", wxPoint(325, 10), wxSize(305, 440));
};

class Application : public wxApp {
public:
  bool OnInit() override {
    this->form = new Form();
    this->form->Show(true);
    return true;
  }
  
private:
  Form* form;
};

wxIMPLEMENT_APP(Application);