#pragma once
#define STRING_COUNT 20
#define STRING_LENGTH 81

/*! DeleteLongComments - ������� ������������� ����������� � ������
	param[in,out] text - �������������� �����
	param[out] - ���-�� ����� ���������� ��������� ��������� ������������
*/

int DeleteLongComments(char text[STRING_COUNT][STRING_LENGTH]);

/*! TrimBetween - ������� ������� ������, ����� ������� ����� � ����-��������, ������ ��������� ������
	param[in,out] pFrom - �������������� �����
	param[in,out] pTo -
*/
void TrimBetween(char *pFrom, char *pTo);

/*! DeleteEmptyStrings - ������� ������ ������ � ������
	param[in,out] text - �������������� �����
*/
void DeleteEmptyStrings(char text[STRING_COUNT][STRING_LENGTH]);

/*! FindLongComment - ������� ������� � ����� ������ ������ � ����� �������������� ����������� � ���������� ��� �����, ���� �������� ��� ����������� ��� 
	param[in,out] text - �������������� �����,
	param[in,out] from - ������� ������ �����������
	param[in,out] fromIndex - ����� ������ ������ �����������
	param[in,out] to - ������� ����� �����������
	param[in,out] toIndex - ����� ������ ����� �����������

	param[out] CommentLength - ����� ������, ���� ������� ���������� �����������
*/
int FindLongComment(char text[STRING_COUNT][STRING_LENGTH], char** from, int* fromIndex, char** to, int* toIndex);

/*! DeleteSingleLineComments - ������� ������������ ����������� � ������
	param[in,out] text - �������������� �����
*/
void DeleteSingleLineComment(char string[STRING_LENGTH]);

/*! DeleteComments - ������� ��� ����������� � ������
	param[in,out] text - �������������� �����
*/
void DeleteComments(char text[STRING_COUNT][STRING_LENGTH]);


