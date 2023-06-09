#define _CRT_SECURE_NO_WARNINGS
#include "Functions.h"
#include <iostream>

int main()
{

	char inputText[STRING_COUNT][STRING_LENGTH] =
	{
	};

	
	//DeleteComments(inputText);

	int M = 0;


	printf("Enter the number of strings: ");
	scanf("%d", &M);
	getchar();

	if (M < 1 || M > STRING_COUNT)
	{
		printf("invalid input data\n");
	}
	else
	{
		printf("Enter text program: \n");

		for (int i = 0; i < M; i++)
		{
			gets_s(inputText[i]);
		}


		DeleteComments(inputText);
		DeleteEmptyStrings(inputText);
		for (int i = 0; i < STRING_COUNT; i++)
			printf("%s\n", inputText[i]);
	}
		
}




void TrimBetween(char *pFrom, char *pTo)
{
	//становимся на позицию первого символа, идущего после закрытия многострочного комментария
	pTo += 2;
	//для каждого символа, стоящего правее конца комментария(пока справа есть символы)
	while (*pTo)
	{
		// перезаписываем теукщий символ на позицию текущего символа комментария
		*pFrom = *pTo;
		// перемещаем позиции с шагом 1
		pTo++;
		pFrom++;
	}
	// когда все символы перезаписаны, заканчиваем строку
	*pFrom = 0;
}

//
void DeleteComments(char text[STRING_COUNT][STRING_LENGTH])
{
	// для каждой строки текста
	for (int i = 0; i < STRING_COUNT; i++)
	{
		// ищем, есть ли однострочные или многострочные комментарии в строке
		char* SingleLineCommentPtr = strstr(text[i], "//");
		char* LongCommentPtr = strstr(text[i], "/*");

		//вычисляем позиции открывающих символов многострочного и однострочного комментария
		int SingleLineCommentPosition = SingleLineCommentPtr - text[i];
		int LongCommentPosition = LongCommentPtr - text[i];
		// пока в строке есть открывающие символы однострочного или многострочного комментария
		while (SingleLineCommentPtr != NULL || LongCommentPtr != NULL)
		{
			//удаляем тот комментарий, чей открывающий символ был найден первым
			if (SingleLineCommentPosition < LongCommentPosition)
			{
				DeleteSingleLineComment(text[i]);
			}
			else
			{
				int CommentLength = DeleteLongComments(text);
			}

			//заново вычисляем позиции открывающих символов многострочного и однострочного комментария в строке после удаления 
			SingleLineCommentPtr = strstr(text[i], "//");
			if (SingleLineCommentPtr == NULL)
			{
				SingleLineCommentPosition = STRING_LENGTH;
			}
			else {
				SingleLineCommentPosition = SingleLineCommentPtr - text[i];
			}


			LongCommentPtr = strstr(text[i], "/*");
			if (LongCommentPtr == NULL)
			{
				LongCommentPosition = STRING_LENGTH;
			}
			else {
				LongCommentPosition = LongCommentPtr - text[i];
			}
		}
	}
	

}

int DeleteLongComments(char text[STRING_COUNT][STRING_LENGTH])
{
	//найти, на скольки строках распологается многострочный комментарий, его начало и конец 
	char* LongCommentOpening = NULL;
	char* LongCommentEnding = NULL;
	int OpeningIndex, EndingIndex;
	int  LongCommentLength = FindLongComment(text, &LongCommentOpening, &OpeningIndex, &LongCommentEnding, &EndingIndex);
	//если комментраий найден, и распологается на нескольких строках
	if (LongCommentLength > 0)
	{
		//удалить все символы, начиная с открытия комментария, в строке, в которой открывается комментарий
		*LongCommentOpening = NULL;
		//удалить каждую следующую строку, пока не дойдем до строки, в которой есть закрывающий символ 
		for (int i = OpeningIndex + 1; i < EndingIndex; i++)
			*text[i] = NULL;
		//удалить все символы в строке,в которой комментарий закрывается, пока не удалим последний символ закрытия комментария
		TrimBetween(text[EndingIndex], LongCommentEnding);
	}

	//если многострочный комментарий распологается на одной строке
	if (LongCommentLength == 0)
	{
		//вычленить его из строки
		TrimBetween(LongCommentOpening, LongCommentEnding);
	}
	//вернуть длину последнего удаленного комментария или признак того, что многострочный комментарий не найден (-1)
	return LongCommentLength;
}

void DeleteSingleLineComment(char string[STRING_LENGTH])
{
	
	char *CommentOpeningPointer = NULL;
		//найти в строке позицию открывающего символа однострочного комментария
		CommentOpeningPointer = strstr(string, "//");
		//если позиция открывающего символа однострочного комментария найдена
		if (CommentOpeningPointer != NULL)
		{
			//удалить все символы в строке, начиная с позиции символа однострочного комментария
			*(CommentOpeningPointer) = 0;

		}
	
}

void DeleteEmptyStrings(char text[STRING_COUNT][STRING_LENGTH])
{
	char textCpy[STRING_COUNT][STRING_LENGTH] = {};

	int textCpyIndex = 0;
	//для каждой строки текста
	for (int i = 0; i < STRING_COUNT; i++)
	{
		//если текущая строка не пустая, то 
		if (strlen(text[i]) != 0)
		{
			//записать ее в пустую копию массива
			strcpy(textCpy[textCpyIndex], text[i]);
			textCpyIndex++;
		}
	}

	// заменить исходный текст его копией без пустых строк
	for (int j = 0; j < STRING_COUNT; j++)
		strcpy(text[j], textCpy[j]);
}


int FindLongComment(char text[STRING_COUNT][STRING_LENGTH], char** from, int* fromIndex, char** to, int* toIndex)
{
	int Commentlength = 0;
	int SearchInProcess = 1;
	//в каждой строке ищем открывающий символ многострочного комментария
	for (int i = 0; i < STRING_COUNT && SearchInProcess; i++)  
	{
		*from = strstr(text[i], "/*");
		//если открывающий символ многострочного комментария найден
		if (*from != NULL)
		{
			//запоминаем номер строки, в которой нашли символ
			*fromIndex = i;
			int HasEnd = 0;
			//в каждой строке, начиная с той, в которой нашли начало, ищем конец комментария
			for (int j = i; j < STRING_COUNT && !HasEnd; j++)
			{
				*to = strstr(text[j], "*/");
				//если конец комментария в строке найден
				if (*to != NULL)
				{
					//запоминаем номер строки его конца
					*toIndex = j;
					//прекращаем поиск закрывающего символа
					HasEnd = 1;
				}
				//если в текущей строке не найден закрывающий комментарий
				if (!HasEnd)
					// увеличиваем длину искомого комментария на 1 и продолжаем поиск конца 
					Commentlength++;
			}

		}
		// если конец найден, прекращаем поиск
		if (*to != NULL) SearchInProcess = 0;
	}
	// если во всем тексте не было найдено начала и конца
	if (*from == NULL && *to == NULL)
		//возвращаем признак того, что комментарий не найден
		Commentlength = -1;
	//возвращаем длину найденного комментария или признак того, что комментарий не найден
	return Commentlength;
}