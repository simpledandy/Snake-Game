//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *FieldPanel;
	TShape *Food;
	TPanel *TopPanel;
	TSpeedButton *SpeedButton1;
	TLabel *Label1;
	TLabel *ScoreLabel;
	TLabel *movesLabel;
	TLabel *Label3;
	TLabel *turnsLabel;
	TLabel *Label5;
	TLabel *energyLabel;
	TLabel *Label4;
	TTimer *Timer1;
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall SpeedButton1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
