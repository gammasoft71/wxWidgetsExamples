#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "Control example", wxDefaultPosition, wxSize(300, 300)) {
    this->control1.SetBackgroundColour(wxTheColourDatabase->Find("Spring Green"));
  }
  
private:
  wxPanel panel {this};
  wxControl control1 {&this->panel, wxID_ANY, wxPoint(50, 50), wxSize(100, 50)};
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);