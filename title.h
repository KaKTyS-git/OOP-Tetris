#pragma once

class Title
{
protected:
	char* gameTitle =
		"TTTTTTTTTTT  EEEEEEEEE  TTTTTTTTTTT  RRRRRRRR   IIIIIIII  SSSSSSSS \n"
		"TT   TT  TT  EE         TT   TT  TT  RR    RR      II     SS       \n"
		"TT   TT  TT  EE         TT   TT  TT  RR    RR      II     SS       \n"
		"     TT      EEEEEEEEE       TT      RRRRRRRR      II     SSSSSSSS \n"
		"     TT      EE              TT      RR   RR       II           SS \n"
		"     TT      EE              TT      RR    RR      II           SS \n"
		"   TTTTTT    EEEEEEEEE     TTTTTT   RRRR     RR IIIIIIII  SSSSSSSS \n\n";

	char* gameMenu =
		"                        1 ===================== Start\n\n"
		"                        2 ===================== Continue\n\n"
		"                        3 ===================== Help\n\n"
		"                        4 ===================== Exit\n\n ";

	char* help =
		"           \x11 =========== Left   \n"
		"           \x10 =========== Right  \n"
		"           \x1F =========== Down   \n"
		"           Space ====== Rotate\n"
		"           P =========== Pause  \n"
		"           ESC ========= Exit   \n"
		"           \n\nPress any key...\n";

	char* gameMode =
		"1 ============= Easy\n"
		"2 ============= Normal\n"
		"3 ============= Hard\n"
		"4 ============= Extreme\n"
		"Please Enter Your Game Mode : ";

public:
	virtual void printTitle() const = 0;
	virtual void printHelp() const = 0;
	virtual void printMenu() const = 0;
};