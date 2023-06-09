#include "pch.h"
#include "CppUnitTest.h"
#include "../14_Marchenko/Functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestDeleteSingleLineComments
{
	TEST_CLASS(TestDeleteSingleLineComments)
	{
	public:
		
		TEST_METHOD(NoComments)
		{
			char text[STRING_COUNT][STRING_LENGTH] =
			{
				"int main()",
				"{",
				"return 0;",
				"}"
			};

			char exp_text[STRING_COUNT][STRING_LENGTH] =
			{
				"int main()",
				"{",
				"return 0;",
				"}"
			};

			for (int i = 0; i < STRING_COUNT; i++)
				DeleteSingleLineComment(text[i]);

			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);
		}

		TEST_METHOD(OneSingleLineComment)
		{
			char text[STRING_COUNT][STRING_LENGTH] =
			{
				"int main()//first comment",
				"{",
				"return 0;",
				"}"
			};

			char exp_text[STRING_COUNT][STRING_LENGTH] =
			{
				"int main()",
				"{",
				"return 0;",
				"}"
			};

			for (int i = 0; i < STRING_COUNT; i++)
				DeleteSingleLineComment(text[i]);

			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);
		}

		TEST_METHOD(SeveralSingleLineComments)
		{
			char text[STRING_COUNT][STRING_LENGTH] =
			{
				"int main()//first comment",
				"{",
				"return 0;//second comment",
				"}"
			};

			char exp_text[STRING_COUNT][STRING_LENGTH] =
			{
				"int main()",
				"{",
				"return 0;",
				"}"
			};

			for (int i = 0; i < STRING_COUNT; i++)
				DeleteSingleLineComment(text[i]);

			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);
		}

		TEST_METHOD(EmbeddedSingleLineComments)
		{
			char text[STRING_COUNT][STRING_LENGTH] =
			{
				"int main()////first comment",
				"{",
				"return 0;",
				"}"
			};

			char exp_text[STRING_COUNT][STRING_LENGTH] =
			{
				"int main()",
				"{",
				"return 0;",
				"}"
			};

			for (int i = 0; i < STRING_COUNT; i++)
				DeleteSingleLineComment(text[i]);

			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);
		}

		TEST_METHOD(MultiLineCommentOnSeveralStringsEmbeddedInSingleLineComments)
		{
			char text[STRING_COUNT][STRING_LENGTH] =
			{
				"int main()",
				"{",
				"///* loooong",
				"//comment*///",
				"return 0;",
				"}"
			};

			char exp_text[STRING_COUNT][STRING_LENGTH] =
			{
				"int main()",
				"{",
				"",
				"",
				"return 0;",
				"}"
			};

			for (int i = 0; i < STRING_COUNT; i++)
				DeleteSingleLineComment(text[i]);

			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);
		}

		TEST_METHOD(AllStringsAreComments)
		{
			char text[STRING_COUNT][STRING_LENGTH] =
			{
				"//int main()",
				"//{",
				"//sfgsfg",
				"//return 0; ",
				"//}"
			};

			char exp_text[STRING_COUNT][STRING_LENGTH] =
			{
				"",
				"",
				"",
				"",
				""
			};

			for (int i = 0; i < STRING_COUNT; i++)
				DeleteSingleLineComment(text[i]);

			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);
		}

		TEST_METHOD(SingleLineCommentInTheMiddleOfString)
		{
			char text[STRING_COUNT][STRING_LENGTH] =
			{
				"int main()",
				"{",
				"int log = // comment 10",
				"return 0;",
				"}"
			};

			char exp_text[STRING_COUNT][STRING_LENGTH] =
			{
				"int main()",
				"{",
				"int log = ",
				"return 0;",
				"}"
			};

			for (int i = 0; i < STRING_COUNT; i++)
				DeleteSingleLineComment(text[i]);

			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);
		}

		TEST_METHOD(MultiLineCommentInTheMiddleOfStringEmdeddedInSingleLineCommentsOnSeveralStrings)
		{
			char text[STRING_COUNT][STRING_LENGTH] =
			{
				"int main()",
				"{",
				"int log =///* loooong",
				"comment//*/ 10",
				"return 0;",
				"}"
			};

			char exp_text[STRING_COUNT][STRING_LENGTH] =
			{
				"int main()",
				"{",
				"int log =",
				"comment",
				"return 0;",
				"}"
			};

			for (int i = 0; i < STRING_COUNT; i++)
			DeleteSingleLineComment(text[i]);
			
			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);
		}

		TEST_METHOD(SingleLineCommentInTheMiddleOfWord)
		{
			char text[STRING_LENGTH] = "int ma//in()";
			

			char exp_text[STRING_LENGTH] = "int ma";

			DeleteSingleLineComment(text);

				Assert::AreEqual(text, exp_text);
		}

		TEST_METHOD(OneStringTextIsSingleLineComment)
		{
			char text[STRING_LENGTH] = "//int main()";

			char exp_text[STRING_LENGTH] = "";

			DeleteSingleLineComment(text);
		
				Assert::AreEqual(text, exp_text);
		}


	};
}
