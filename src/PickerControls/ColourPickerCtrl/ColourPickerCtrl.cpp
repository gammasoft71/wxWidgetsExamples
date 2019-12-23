#include <wx/wx.h>
#include <wx/clrpicker.h>

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "ColourPicker example", wxDefaultPosition, wxSize(300, 300)) {
    testZone->SetBackgroundColour(wxTheColourDatabase->Find("Red"));
    picker->SetColour(testZone->GetBackgroundColour());
    picker->Bind(wxEVT_COLOURPICKER_CHANGED, [this](wxColourPickerEvent& event) {
      testZone->SetBackgroundColour(event.GetColour());
      testZone->Refresh();
    });
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxPanel* testZone = new wxPanel(panel, wxID_ANY, {10, 50}, {200, 100}, wxTAB_TRAVERSAL | wxBORDER_SUNKEN);
  wxColourPickerCtrl* picker = new wxColourPickerCtrl(panel, wxID_ANY, wxColour(0, 0, 0), {10, 10}, {100, 25});
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
