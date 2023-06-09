#pragma once
#define STRING_COUNT 20
#define STRING_LENGTH 81

/*! DeleteLongComments - удаляет многострочные комментарии в тексте
	param[in,out] text - обрабатываемый текст
	param[out] - кол-во строк занимаемых последним удаленным комментарием
*/

int DeleteLongComments(char text[STRING_COUNT][STRING_LENGTH]);

/*! TrimBetween - удаляет участок строки, путем перноса части с нуль-символом, правее указателя начала
	param[in,out] pFrom - обрабатываемый текст
	param[in,out] pTo -
*/
void TrimBetween(char *pFrom, char *pTo);

/*! DeleteEmptyStrings - удаляет пустые строки в тексте
	param[in,out] text - обрабатываемый текст
*/
void DeleteEmptyStrings(char text[STRING_COUNT][STRING_LENGTH]);

/*! FindLongComment - находит позицию и номер строки начала и конца многострочного комментария и возвращает его длину, либо произнак что комментария нет 
	param[in,out] text - обрабатываемый текст,
	param[in,out] from - позиция начала комментария
	param[in,out] fromIndex - номер строки начала комментария
	param[in,out] to - позиция конца комментария
	param[in,out] toIndex - номер строки конца комментария

	param[out] CommentLength - длина строки, либо признак отсутствия комментария
*/
int FindLongComment(char text[STRING_COUNT][STRING_LENGTH], char** from, int* fromIndex, char** to, int* toIndex);

/*! DeleteSingleLineComments - удаляет однострочные комментарии в тексте
	param[in,out] text - обрабатываемый текст
*/
void DeleteSingleLineComment(char string[STRING_LENGTH]);

/*! DeleteComments - удаляет все комментарии в тексте
	param[in,out] text - обрабатываемый текст
*/
void DeleteComments(char text[STRING_COUNT][STRING_LENGTH]);


