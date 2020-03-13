//---------------------------------------------------------------------------

#ifndef clocheH
#define clocheH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <winsock2.h>
#include "fonctions.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Composants gérés par l'EDI
	TButton *connexion;
	TButton *cloche1;
	TButton *cloche2;
	TButton *cloche3;
	TButton *cloche4;
	TButton *close;
	TEdit *Edit1;
	TButton *melodie;
	TButton *fichier;
	void __fastcall connexionClick(TObject *Sender);
	void __fastcall cloche1Click(TObject *Sender);
	void __fastcall closeClick(TObject *Sender);
	void __fastcall cloche2Click(TObject *Sender);
	void __fastcall cloche3Click(TObject *Sender);
	void __fastcall cloche4Click(TObject *Sender);
	void __fastcall Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall melodieClick(TObject *Sender);
	void __fastcall fichierClick(TObject *Sender);
	void __fastcall UdpSocket1Connect(TObject *Sender);
private:	// Déclarations utilisateur
	cloche *ding;
	SOCKET sock;
public:		// Déclarations utilisateur
	__fastcall TForm1(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
