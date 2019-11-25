//---------------------------------------------------------------------------

#ifndef fonctionsH
#define fonctionsH
#include <Windows.h>
//---------------------------------------------------------------------------
 class cloche
{
	private :
		SOCKET sock;

	public ://declarations des fonctions
	  cloche(SOCKET sock);
	  ~cloche();
	  void cloche1();
	  void cloche2();
	  void cloche3();
	  void cloche4();
      void toutCloche();
};

#endif


