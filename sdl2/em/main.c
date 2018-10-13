/**
 * @file	main.c
 * @brief	メイン
 */

#include "compiler.h"
#include "..\xmil.h"
#include "..\fontmng.h"

/**
 * メイン
 * @param[in] argc 引数
 * @param[in] argv 引数
 * @return リザルト コード
 */
int main(int argc, char *argv[])
{
#ifdef WIN32
	UINT nLength;
	TCHAR szFont[MAX_PATH];

	nLength = GetWindowsDirectory(szFont, SDL_arraysize(szFont));
	lstrcpy(szFont + nLength, TEXT("\\Fonts\\msgothic.ttc"));
	fontmng_setdeffontname(szFont);
#endif
	return xmil_main(argc, argv);
}
