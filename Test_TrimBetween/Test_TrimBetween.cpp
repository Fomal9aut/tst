#include "pch.h"
#include "CppUnitTest.h"
#include "../14_Marchenko/Functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestTrimBetween
{
	TEST_CLASS(TestTrimBetween)
	{
	public:
		
		TEST_METHOD(OneMultiLineCommentInTheMiddleOfString)
		{
			char text[STRING_LENGTH] = "int /*long comment*/ main()";
			char exp_text[STRING_LENGTH] = "int  main()";
			char* from = strstr(text, "/*");
			char* to = strstr(text, "*/");
			TrimBetween(from, to);

			Assert::AreEqual(text, exp_text);
		}

		TEST_METHOD(OneMultiLineCommentInTheBeginingOfString)
		{
			char text[STRING_LENGTH] = "/*long comment*/ int main()";
			char exp_text[STRING_LENGTH] = " int main()";
			char* from = strstr(text, "/*");
			char* to = strstr(text, "*/");
			TrimBetween(from, to);

			Assert::AreEqual(text, exp_text);
		}

		TEST_METHOD(OneMultiLineCommentInTheEndOfString)
		{
			char text[STRING_LENGTH] = "int main() /*long comment*/";
			char exp_text[STRING_LENGTH] = "int main() ";
			char* from = strstr(text, "/*");
			char* to = strstr(text, "*/");
			TrimBetween(from, to);

			Assert::AreEqual(text, exp_text);
		}

		TEST_METHOD(SingleLineCommentEmbeddedinMultiLineComment)
		{
			char text[STRING_LENGTH] = "int /*long // comment*/ main()";
			char exp_text[STRING_LENGTH] = "int  main()";
			char* from = strstr(text, "/*");
			char* to = strstr(text, "*/");
			TrimBetween(from, to);

			Assert::AreEqual(text, exp_text);
		}

		TEST_METHOD(MultiLineCommentEmbeddedinMultiLineComment)
		{
			char text[STRING_LENGTH] = "int /*long /*embedded*/ comment*/ main()";
			char exp_text[STRING_LENGTH] = "int  comment*/ main()";
			char* from = strstr(text, "/*");
			char* to = strstr(text, "*/");
			TrimBetween(from, to);

			Assert::AreEqual(text, exp_text);
		}

		TEST_METHOD(OneMultiLineCommentInTheMiddleOfWord)
		{
			char text[STRING_LENGTH] = "ma/*long comment*/in()";
			char exp_text[STRING_LENGTH] = "main()";
			char* from = strstr(text, "/*");
			char* to = strstr(text, "*/");
			TrimBetween(from, to);

			Assert::AreEqual(text, exp_text);
		}
	};
}
