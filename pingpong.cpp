//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "pingpong.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

        int x =-8;
        int y = -8;
        int ruch = -3;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::timer_ballTimer(TObject *Sender)
{
        ball->Left += x;
        ball->Top += y;
        przeszkodza->Top -=ruch;

        if(przeszkodza->Top >=840) ruch = -ruch;
        if(przeszkodza->Top <=0)ruch = -ruch;

        //odbijanie od gornej sciany
if(ball->Top < tlo->Top) y=-y;

        //odbijanie od dolnej sciany
if(ball->Top + ball->Height >=  tlo->Height)y=-y;

        //odbijanie od paletki 1
if(ball->Left < tlo->Left)
{
timer_ball->Enabled = false;
ball->Visible = false;
 Again->Visible = true;
 przeszkodza->Visible = false;


}
else if(ball->Top > paletka1->Top && ball->Top < paletka1->Top+150 && ball->Left-25 < paletka1->Left){
 if(x<0) x=-x;
}

        //odbijanie od paletki 2

if(ball->Left > paletka2->Left){
    timer_ball->Enabled = false;
    ball->Visible = false;
     Again->Visible = true;
     przeszkodza->Visible = false;
}
else if(ball->Top> paletka2->Top && ball->Top < paletka2->Top + 150 && ball->Left+45 > paletka2->Left)
{
   x=-x;
}

if(ball->Left > 890 && ball->Left < 930 && ball->Top > przeszkodza->Top && ball->Top < przeszkodza->Top + przeszkodza->Height){
        x=-x;
        }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer_paletka2_lewoTimer(TObject *Sender)
{
          if(paletka2->Top > 15)
        paletka2->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer_paletka2_prawoTimer(TObject *Sender)
{
          if(paletka2->Top + paletka2->Height < tlo->Height-15)
        paletka2->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
          if(Key ==  VK_UP) Timer_paletka2_lewo->Enabled = true;
          if(Key ==  VK_DOWN)Timer_paletka2_prawo->Enabled = true;
          if(Key == 0x41) Timer_paletka1_lewo->Enabled = true;
          if(Key == 0x5A) Timer_paletka1_prawo->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
     if(Key == VK_UP) Timer_paletka2_lewo->Enabled = false;
          if(Key == VK_DOWN) Timer_paletka2_prawo->Enabled = false;
         if(Key == 0x41) Timer_paletka1_lewo->Enabled = false;
          if(Key == 0x5A) Timer_paletka1_prawo->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer_paletka1_lewoTimer(TObject *Sender)
{
         if(paletka1->Top > 15)
        paletka1->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer_paletka1_prawoTimer(TObject *Sender)
{
            if(paletka1->Top + paletka1->Height < tlo->Height-15)
            paletka1->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::AgainClick(TObject *Sender)
{
              ball->Left = 500;
              ball->Top = 500;
              paletka1->Left = 0;
              paletka1->Top = 424;
              paletka2->Left = 1880;
              paletka2->Top = 424;
              przeszkodza->Visible = true;

        ball->Visible = true;
        x=-8; y=-8;
        timer_ball->Enabled = true;
        Again->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::StartGameClick(TObject *Sender)
{
        ball->Visible = true;
        timer_ball->Enabled=true;
        paletka1->Visible = true;
        paletka2->Visible = true;
        StartGame->Visible=false;
        ZasadyGry->Visible=false;
        zasady->Visible=false;
        Timer1->Enabled=true;
        KoniecGry->Visible = false;
        przeszkodza->Visible = true;
        

}
//---------------------------------------------------------------------------
void __fastcall TForm1::zasadyClick(TObject *Sender)
{
        ZasadyGry->Visible = true;
        zasady->Visible = false;        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::KoniecGryClick(TObject *Sender)
{
        exit(0);
}
//---------------------------------------------------------------------------

