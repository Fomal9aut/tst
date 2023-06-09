#include "pch.h"
#include "CppUnitTest.h"
#include "../14_Marchenko/Functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestDeleteComments
{
	TEST_CLASS(TestDeleteComments)
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

			DeleteComments(text);
			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);
		}

		TEST_METHOD(OneSingleLineComment)
		{
			char text[STRING_COUNT][STRING_LENGTH] =
			{
				"int main()",
				"{",
				"return 0;//comment",
				"}"
			};

			char exp_text[STRING_COUNT][STRING_LENGTH] =
			{
				"int main()",
				"{",
				"return 0;",
				"}"
			};

			DeleteComments(text);
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

			DeleteComments(text);
			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);
		}


		TEST_METHOD(MultiLineCommentsOnOneString)
		{
			char text[STRING_COUNT][STRING_LENGTH] =
			{
				"int main()/*one*/ /*two*/",
				"{",
				"return 0;//second comment",
				"}"
			};

			char exp_text[STRING_COUNT][STRING_LENGTH] =
			{
				"int main() ",
				"{",
				"return 0;",
				"}"
			};

			DeleteComments(text);
			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);
		}

		TEST_METHOD(EmbeddedSingleLineComments)
		{
			char text[STRING_COUNT][STRING_LENGTH] =
			{
				"int main()",
				"{",
				"return 0;////",
				"}"
			};

			char exp_text[STRING_COUNT][STRING_LENGTH] =
			{
				"int main()",
				"{",
				"return 0;",
				"}"
			};

			DeleteComments(text);
			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);
		}

		TEST_METHOD(LongCommentOnSeveralStrings)
		{
			char text[STRING_COUNT][STRING_LENGTH] =
			{
				"int main()",
				"{",
				"/* looong",
				"comment*/",
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

			DeleteComments(text);
			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);
		}

		TEST_METHOD(LongCommentOnOneString)
		{
			char text[STRING_COUNT][STRING_LENGTH] =
			{
				"int main()",
				"{",
				"/* looong comment*/",
				"return 0;",
				"}"
			};

			char exp_text[STRING_COUNT][STRING_LENGTH] =
			{
				"int main()",
				"{",
				"",
				"return 0;",
				"}"
			};

			DeleteComments(text);
			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);
		}

		TEST_METHOD(LongCommentInTheMiddleOfString)
		{
			char text[STRING_COUNT][STRING_LENGTH] =
			{
				"int main()",
				"{",
				"int log=/* looong comment*/10",
				"return 0;",
				"}"
			};

			char exp_text[STRING_COUNT][STRING_LENGTH] =
			{
				"int main()",
				"{",
				"int log=10",
				"return 0;",
				"}"
			};

			DeleteComments(text);
			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);
		}

		TEST_METHOD(LongCommentInTheMiddleOfStringOnSeveralStrings)
		{
			char text[STRING_COUNT][STRING_LENGTH] =
			{
				"int main()",
				"{",
				"int log= /* looong"
				"comment*/ 10",
				"return 0;",
				"}"
			};

			char exp_text[STRING_COUNT][STRING_LENGTH] =
			{
				"int main()",
				"{",
				"int log= "
				" 10",
				"return 0;",
				"}"
			};

			DeleteComments(text);
			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);
		}

		TEST_METHOD(LongCommentSymbolsEmbeddedInSingleLineComments)
		{
			char text[STRING_COUNT][STRING_LENGTH] = {
				"int main()",
				"{// int i; /*",
				"i*=i;",
				"//return i; */",
				"}"
			};

			char exp_text[STRING_COUNT][STRING_LENGTH] = {
				"int main()",
				"{",
				"i*=i;",
				"",
				"}"
			};


			DeleteComments(text);

			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);
		}

		TEST_METHOD(ComplexTest)
		{
			char text[STRING_COUNT][STRING_LENGTH] = {
				"int/*afadsfda*/ main()/*  adsfdaf*/ /*adf",
				"//asdfa*/sdfasdfdas",
				"{/*third comment*/",
				"//fsgsdfgsfdg",
				"//sfgsf///dg/*-----sdfg",
				"//sdf//gsdfgsdf*/g",
				"/*sdfafasd//asfasd*/",
				"return 0;//gfsgdsfdgsfgdsfgfsdg",
				"}"
			};

			char exp_text[STRING_COUNT][STRING_LENGTH] = {
				"int main() ",
				"sdfasdfdas",
				"{",
				"",
				"",
				"g",
				"",
				"return 0;",
				"}"
			};

			DeleteComments(text);

			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);

		}
	};
}
