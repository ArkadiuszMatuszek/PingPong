//---------------------------------------------------------------------------

#ifndef pingpongH
#define pingpongH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *tlo;
        TImage *ball;
        TTimer *timer_ball;
        TImage *paletka1;
        TImage *paletka2;
        TTimer *Timer_paletka1_lewo;
        TTimer *Timer_paletka1_prawo;
        TTimer *Timer_paletka2_lewo;
        TTimer *Timer_paletka2_prawo;
        TButton *Again;
        TButton *StartGame;
        TButton *zasady;
        TImage *ZasadyGry;
        TImage *przeszkodza;
        TTimer *Timer1;
        TButton *KoniecGry;
        void __fastcall timer_ballTimer(TObject *Sender);
        void __fastcall Timer_paletka1_lewoTimer(TObject *Sender);
        void __fastcall Timer_paletka1_prawoTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Timer_paletka2_lewoTimer(TObject *Sender);
        void __fastcall Timer_paletka2_prawoTimer(TObject *Sender);
        void __fastcall AgainClick(TObject *Sender);
        void __fastcall StartGameClick(TObject *Sender);
        void __fastcall zasadyClick(TObject *Sender);
        void __fastcall KoniecGryClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
