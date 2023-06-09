#include "pch.h"
#include "CppUnitTest.h"
#include "../14_Marchenko/Functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestDeleteEmptyStrings
{
	TEST_CLASS(TestDeleteEmptyStrings)
	{
	public:
		
		TEST_METHOD(NoEmptyStrings)
		{
			char text[STRING_COUNT][STRING_LENGTH] =
			{
				"int main()",
				"{",
				"int log = 10",
				"return 0;",
				"}"
			};

			char exp_text[STRING_COUNT][STRING_LENGTH] =
			{
				"int main()",
				"{",
				"int log = 10",
				"return 0;",
				"}"
			};

			DeleteEmptyStrings(text);
			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);
		}

		TEST_METHOD(OneEmptyStrings)
		{
			char text[STRING_COUNT][STRING_LENGTH] =
			{
				"int main()",
				"{",
				"int log = 10",
				"",
				"return 0;",
				"}"
			};

			char exp_text[STRING_COUNT][STRING_LENGTH] =
			{
				"int main()",
				"{",
				"int log = 10",
				"return 0;",
				"}"
			};

			DeleteEmptyStrings(text);
			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);
		}

		TEST_METHOD(SeveralEmptyStrings)
		{
			char text[STRING_COUNT][STRING_LENGTH] =
			{
				"int main()",
				"{",
				"",
				"int log = 10",
				"",
				"return 0;",
				"}"
			};

			char exp_text[STRING_COUNT][STRING_LENGTH] =
			{
				"int main()",
				"{",
				"int log = 10",
				"return 0;",
				"}"
			};

			DeleteEmptyStrings(text);
			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);
		}

		TEST_METHOD(SeveralEmptyStringsInARow)
		{
			char text[STRING_COUNT][STRING_LENGTH] =
			{
				"int main()",
				"{",
				"int log = 10",
				"",
				"",
				"return 0;",
				"}"
			};

			char exp_text[STRING_COUNT][STRING_LENGTH] =
			{
				"int main()",
				"{",
				"int log = 10",
				"return 0;",
				"}"
			};

			DeleteEmptyStrings(text);
			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);
		}

		TEST_METHOD(EmptySpaceInAString)
		{
			char text[STRING_COUNT][STRING_LENGTH] =
			{
				"int main()",
				"{",
				"int log =             10",
				"return 0;",
				"}"
			};

			char exp_text[STRING_COUNT][STRING_LENGTH] =
			{
				"int main()",
				"{",
				"int log =             10",
				"return 0;",
				"}"
			};

			DeleteEmptyStrings(text);
			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);
		}

		TEST_METHOD(EmptyText)
		{
			char text[STRING_COUNT][STRING_LENGTH] =
			{
				"",
				"",
				"",
				"",
				""
			};

			char exp_text[STRING_COUNT][STRING_LENGTH] =
			{

			};

			DeleteEmptyStrings(text);
			for (int i = 0; i < STRING_COUNT; i++)
				Assert::AreEqual(text[i], exp_text[i]);
		}
	};
}
