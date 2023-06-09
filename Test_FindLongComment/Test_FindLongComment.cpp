#include "pch.h"
#include "CppUnitTest.h"
#include "../14_Marchenko/Functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestFindLongComment
{
	TEST_CLASS(TestFindLongComment)
	{
	public:
		
		TEST_METHOD(NoComments)
		{
			char text[STRING_COUNT][STRING_LENGTH] = {
				"/*int  main()",
				"char text[20][81];"
				"puts(text)",
				"return -1; "
			};
			char* LongCommentOpening = NULL;
			char* LongCommentEnding = NULL;
			int OpeningIndex, EndingIndex;

			char* exp_LongCommentOpening = strstr(text[0], "/*");
			char* exp_LongCommentEnding = strstr(text[3], "*/");
			int exp_OpeningIndex = 0, exp_EndingIndex = 0;
			int  exp_LongCommentLength = -1;

			int  LongCommentLength = FindLongComment(text, &LongCommentOpening, &OpeningIndex, &LongCommentEnding, &EndingIndex);



			Assert::AreEqual(LongCommentLength, exp_LongCommentLength);
			Assert::AreEqual(OpeningIndex, exp_OpeningIndex);
			
		}

		TEST_METHOD(OneLongCommentInString)
		{
			char text[STRING_COUNT][STRING_LENGTH] = { "/*int  main()*/" };
			char* LongCommentOpening = NULL;
			char* LongCommentEnding = NULL;
			int OpeningIndex, EndingIndex;

			char* exp_LongCommentOpening = strstr(text[STRING_COUNT], "/*");
			char* exp_LongCommentEnding = strstr(text[STRING_COUNT], "*/");
			int exp_OpeningIndex = 0, exp_EndingIndex = 0;
			int  exp_LongCommentLength = 0;

			int  LongCommentLength = FindLongComment(text, &LongCommentOpening, &OpeningIndex, &LongCommentEnding, &EndingIndex);



			Assert::AreEqual(LongCommentLength, exp_LongCommentLength);
			Assert::AreEqual(OpeningIndex, exp_OpeningIndex);
			Assert::AreEqual(EndingIndex, exp_EndingIndex);
		}

		TEST_METHOD(OneLongCommentInTwoStrings)
		{
			char text[STRING_COUNT][STRING_LENGTH] = {
				"/*int  main()",
				"asdfaf*/"
			};
			char* LongCommentOpening = NULL;
			char* LongCommentEnding = NULL;
			int OpeningIndex, EndingIndex;

			char* exp_LongCommentOpening = strstr(text[0], "/*");
			char* exp_LongCommentEnding = strstr(text[1], "*/");
			int exp_OpeningIndex = 0, exp_EndingIndex = 1;
			int  exp_LongCommentLength = 1;

			int  LongCommentLength = FindLongComment(text, &LongCommentOpening, &OpeningIndex, &LongCommentEnding, &EndingIndex);



			Assert::AreEqual(LongCommentLength, exp_LongCommentLength);
			Assert::AreEqual(OpeningIndex, exp_OpeningIndex);
			Assert::AreEqual(EndingIndex, exp_EndingIndex);
		}

		TEST_METHOD(OneLongCommentInSeveralStrings)
		{
			char text[STRING_COUNT][STRING_LENGTH] = {
				"/*int  main()",
				"char text[20][81];"
				"puts(text)",
				"return -1; */"
			};
			char* LongCommentOpening = NULL;
			char* LongCommentEnding = NULL;
			int OpeningIndex, EndingIndex;

			char* exp_LongCommentOpening = strstr(text[0], "/*");
			char* exp_LongCommentEnding = strstr(text[3], "*/");
			int exp_OpeningIndex = 0, exp_EndingIndex = 2;
			int  exp_LongCommentLength = 2;

			int  LongCommentLength = FindLongComment(text, &LongCommentOpening, &OpeningIndex, &LongCommentEnding, &EndingIndex);



			Assert::AreEqual(LongCommentLength, exp_LongCommentLength);
			Assert::AreEqual(OpeningIndex, exp_OpeningIndex);
			Assert::AreEqual(EndingIndex, exp_EndingIndex);
		}


		TEST_METHOD(TwoLongCommentInText)
		{
			char text[STRING_COUNT][STRING_LENGTH] = {
				"/*int  main()",
				"char*/ text[20][81];"
				"/*puts(text)",
				"return -1; */"
			};
			char* LongCommentOpening = NULL;
			char* LongCommentEnding = NULL;
			int OpeningIndex, EndingIndex;

			char* exp_LongCommentOpening = strstr(text[0], "/*");
			char* exp_LongCommentEnding = strstr(text[1], "*/");
			int exp_OpeningIndex = 0, exp_EndingIndex = 1;
			int  exp_LongCommentLength = 1;

			int  LongCommentLength = FindLongComment(text, &LongCommentOpening, &OpeningIndex, &LongCommentEnding, &EndingIndex);



			Assert::AreEqual(LongCommentLength, exp_LongCommentLength);
			Assert::AreEqual(OpeningIndex, exp_OpeningIndex);
			Assert::AreEqual(EndingIndex, exp_EndingIndex);
		}


		TEST_METHOD(TwoLongCommentInTextIntersection)
		{
			char text[STRING_COUNT][STRING_LENGTH] = {
				"/*int  main()",
				"char /*text[20][81];"
				"puts*/(text)",
				"return -1; */"
			};
			char* LongCommentOpening = NULL;
			char* LongCommentEnding = NULL;
			int OpeningIndex, EndingIndex;

			char* exp_LongCommentOpening = strstr(text[0], "/*");
			char* exp_LongCommentEnding = strstr(text[2], "*/");
			int exp_OpeningIndex = 0, exp_EndingIndex = 1;
			int  exp_LongCommentLength = 1;

			int  LongCommentLength = FindLongComment(text, &LongCommentOpening, &OpeningIndex, &LongCommentEnding, &EndingIndex);



			Assert::AreEqual(LongCommentLength, exp_LongCommentLength);
			Assert::AreEqual(OpeningIndex, exp_OpeningIndex);
			Assert::AreEqual(EndingIndex, exp_EndingIndex);
		}
	};
}
