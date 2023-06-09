#include "pch.h"
#include "CppUnitTest.h"
#include "../14_Marchenko/Functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestDeleteLongComments
{
	TEST_CLASS(TestDeleteLongComments)
	{
	public:

		TEST_METHOD(LongCommentOnSeveralStrings)
		{
			char text[STRING_COUNT][STRING_LENGTH] = {
				"int main(){}/*aaaa",
				"asdfaf",
				"*/bbbb"
			};

			char exp_text[STRING_COUNT][STRING_LENGTH] = {
				"int main(){}",
				"",
				"bbbb"
			};

			DeleteLongComments(text);

			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);

		}

		TEST_METHOD(EmptyComment)
		{
			char text[STRING_COUNT][STRING_LENGTH] = {
				"/**/",
				"asdfaf"
			};

			char exp_text[STRING_COUNT][STRING_LENGTH] = {
				"",
				"asdfaf"
			};

			DeleteLongComments(text);

			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);

		}
		
		TEST_METHOD(OneLongCommentInTwoStrings)
		{
			char text[STRING_COUNT][STRING_LENGTH] = {
				"/*int  main()",
				"asdfaf*/"
			};

			char exp_text[STRING_COUNT][STRING_LENGTH] = {
			"",
			""
			};

			DeleteLongComments(text);

			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);

		}

		TEST_METHOD(NoComments)
		{
			char text[STRING_COUNT][STRING_LENGTH] = {
				"int  main()",
				"asdfaf"
			};

			char exp_text[STRING_COUNT][STRING_LENGTH] = {
				"int  main()",
				"asdfaf"
			};

			DeleteLongComments(text);

			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);

		}


		TEST_METHOD(NoLongComments)
		{
			char text[STRING_COUNT][STRING_LENGTH] = {
				"//int  main()",
				"//asdfaf"
			};

			char exp_text[STRING_COUNT][STRING_LENGTH] = {
				"//int  main()",
				"//asdfaf"
			};

			DeleteLongComments(text);

			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);

		}



		TEST_METHOD(LongCommentInTheBeginingOfTheString)
		{
			char text[STRING_COUNT][STRING_LENGTH] = {
				"/*loooooooooooong comment*/int  main()",
				"asdfaf"
			};

			char exp_text[STRING_COUNT][STRING_LENGTH] = {
				"int  main()",
				"asdfaf"
			};

			DeleteLongComments(text);

			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);

		}


		TEST_METHOD(LongCommentInTheMiddleOfTheString)
		{
			char text[STRING_COUNT][STRING_LENGTH] = {
				"int/*loooooooooooong comment*/  main()",
				"asdfaf"
			};

			char exp_text[STRING_COUNT][STRING_LENGTH] = {
				"int  main()",
				"asdfaf"
			};

			DeleteLongComments(text);

			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);

		}

		TEST_METHOD(LongCommentInTheEndOfTheString)
		{
			char text[STRING_COUNT][STRING_LENGTH] = {
				"int  main()/*looooooooooong comment*/",
				"asdfaf"
			};

			char exp_text[STRING_COUNT][STRING_LENGTH] = {
				"int  main()",
				"asdfaf"
			};

			DeleteLongComments(text);

			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);

		}

		TEST_METHOD(TwoLongCommentsInTheString)
		{
			char text[STRING_COUNT][STRING_LENGTH] = {
				"int /*loooooong comment*/ main()/*looooooooooong comment2*/",
				"asdfaf"
			};

			char exp_text[STRING_COUNT][STRING_LENGTH] = {
				"int  main()",
				"asdfaf"
			};

			int IsAnyComments = DeleteLongComments(text);

			while (IsAnyComments != -1)
				IsAnyComments = DeleteLongComments(text);

			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);
		}

		TEST_METHOD(SeveralLongCommentsInTheString)
		{
			char text[STRING_COUNT][STRING_LENGTH] = {
				"int /*loooooong comment*/ main(/*looong cooment2*/)/*looooooooooong comment3*/",
				"asdfaf"
			};

			char exp_text[STRING_COUNT][STRING_LENGTH] = {
				"int  main()",
				"asdfaf"
			};

			int IsAnyComments = DeleteLongComments(text);

			while (IsAnyComments != -1)
				IsAnyComments = DeleteLongComments(text);

			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);
		}

		TEST_METHOD(SeveralLongCommentsInSeveralString)
		{
			char text[STRING_COUNT][STRING_LENGTH] = {
				"int /*loooooong comment*/ main(/*looong cooment2*/)/*looooooooooong comment3*/",
				"/*loong comment4*/asdfaf"
			};

			char exp_text[STRING_COUNT][STRING_LENGTH] = {
				"int  main()",
				"asdfaf"
			};

			int IsAnyComments = DeleteLongComments(text);

			while (IsAnyComments != -1)
				IsAnyComments = DeleteLongComments(text);

			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);
		}

		TEST_METHOD(AllStringAreLongComments)
		{
			char text[STRING_COUNT][STRING_LENGTH] = {
				"/*int loooooong comment main(looong cooment2)looooooooooong comment3*/",
				"/*loong comment4asdfaf*/"
			};

			char exp_text[STRING_COUNT][STRING_LENGTH] = {
				"",
				""
			};

			int IsAnyComments = DeleteLongComments(text);

			while (IsAnyComments != -1)
				IsAnyComments = DeleteLongComments(text);

			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);
		}

		TEST_METHOD(NoTextWithoutLongComments)
		{
			char text[STRING_COUNT][STRING_LENGTH] = {
				"/*int loooooong comment main(looong cooment2)looooooooooong comment3",
				"",
				"loong comment4asdfaf*/"
			};

			char exp_text[STRING_COUNT][STRING_LENGTH] = {
				"",
				"",
				""
			};

			int IsAnyComments = DeleteLongComments(text);

			while (IsAnyComments != -1)
				IsAnyComments = DeleteLongComments(text);

			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);
		}


		TEST_METHOD(SingleCommentsEmbeddedInLongComments)
		{
			char text[STRING_COUNT][STRING_LENGTH] = {
				"/*int lo/////////oong comment*/ main(/*long///// cooment2*/)/*lng com/////ment*/",
				""
			};

			char exp_text[STRING_COUNT][STRING_LENGTH] = {
				" main()",
				""
			};

			int IsAnyComments = DeleteLongComments(text);

			while (IsAnyComments != -1)
				IsAnyComments = DeleteLongComments(text);

			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);
		}

		
	};
}
