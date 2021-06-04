#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include "..\Course_Work\Edmonds-Karp.cpp"
#include "..\Course_Work\Graph.cpp"
#include "..\Course_Work\List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestCourseWork
{
	TEST_CLASS(LinkedListTest)
	{
	public:

		TEST_METHOD(ConstructorTest)
		{
			List<int> lst;
			Assert::IsTrue(lst.GetSize() == 0);
		}
		TEST_METHOD(IsEmptyTest1)
		{
			List<int> lst;
			Assert::IsTrue(lst.isEmpty());
		}
		TEST_METHOD(IsEmptyTest2)
		{
			List<int> lst;
			lst.push_back(3);
			Assert::IsTrue(lst.isEmpty() == false);
		}
		TEST_METHOD(AtTest1)
		{
			List<int> lst;
			lst.push_back(3);
			Assert::IsTrue(lst.at(0) == 3);
		}
		TEST_METHOD(AtTest2)
		{
			List<int> lst;
			lst.push_back(3);
			lst.push_front(2);
			Assert::IsTrue(lst.at(0) == 2, L"Assert 1");
			Assert::IsTrue(lst.at(1) == 3, L"Assert 2");
			Assert::IsTrue(lst.GetSize() == 2, L"Assert 3");
		}
		TEST_METHOD(AtTest3)
		{
			List<int> lst;
			lst.push_back(3);
			try
			{
				lst.at(-5);
			}
			catch (const char* error)
			{
				Assert::AreEqual(error, "Error! Incorrect input.");
			}
		}
		TEST_METHOD(GetSizeTest1)
		{
			List<int> lst;
			Assert::IsTrue(lst.GetSize() == 0);
		}
		TEST_METHOD(GetSizeTest2)
		{
			List<int> lst;
			lst.push_back(3);
			lst.push_front(2);
			Assert::IsTrue(lst.GetSize() == 2);
		}
		TEST_METHOD(GetSizeTest3)
		{
			List<int> lst;
			lst.push_back(3);
			lst.push_front(2);
			lst.pop_back();
			lst.pop_front();
			Assert::IsTrue(lst.GetSize() == 0);
		}

		TEST_METHOD(PushBackTest1)
		{
			List<int> lst;
			lst.push_back(3);
			Assert::IsTrue(lst.GetSize() == 1, L"Assert 1");
			Assert::IsTrue(lst.at(0) == 3, L"Assert 2");
		}
		TEST_METHOD(PushBackTest2)
		{
			List<int> lst;
			lst.push_back(0);
			lst.push_back(1);
			lst.push_back(2);
			lst.push_back(3);
			Assert::IsTrue(lst.GetSize() == 4, L"Assert 1");
			Assert::IsTrue(lst.at(3) == 3, L"Assert 2");
		}
		TEST_METHOD(PushFrontTest1)
		{
			List<int> lst;
			lst.push_front(3);
			Assert::IsTrue(lst.GetSize() == 1, L"Assert 1");
			Assert::IsTrue(lst.at(0) == 3, L"Assert 2");
		}
		TEST_METHOD(PushFrontTest2)
		{
			List<int> lst;
			lst.push_front(0);
			lst.push_front(1);
			lst.push_front(2);
			lst.push_front(3);
			Assert::IsTrue(lst.GetSize() == 4, L"Assert 1");
			Assert::IsTrue(lst.at(3) == 0, L"Assert 2");
		}
		TEST_METHOD(PopBackTest1)
		{
			List<int> lst;
			lst.push_back(0);
			lst.push_back(1);
			lst.push_back(2);
			lst.push_back(3);
			lst.pop_back();
			Assert::IsTrue(lst.GetSize() == 3);
		}
		TEST_METHOD(PopBackTest2)
		{
			List<int> lst;
			lst.push_back(0);
			lst.pop_back();
			Assert::IsTrue(lst.GetSize() == 0);
		}
		TEST_METHOD(PopBackTest3)
		{
			List<int> lst;
			try
			{
				lst.pop_back();
			}
			catch (const char* error)
			{
				Assert::AreEqual(error, "Error! Linked list is Empty.");
			}
		}
		TEST_METHOD(PopFrontTest1)
		{
			List<int> lst;
			lst.push_back(0);
			lst.push_back(1);
			lst.push_back(2);
			lst.push_back(3);
			lst.pop_front();
			Assert::IsTrue(lst.at(0) == 1, L"Assert 1");
			Assert::IsTrue(lst.at(1) == 2, L"Assert 2");
			Assert::IsTrue(lst.GetSize() == 3, L"Assert 3");
		}
		TEST_METHOD(PopFrontTest2)
		{
			List<int> lst;
			lst.push_back(0);
			lst.pop_front();
			Assert::IsTrue(lst.isEmpty(), L"Assert 1");
		}
		TEST_METHOD(PopFrontTest3)
		{
			List<int> lst;
			try
			{
				lst.pop_front();
			}
			catch (const char* error)
			{
				Assert::AreEqual(error, "Error! Linked list is Empty.");
			}
		}
		TEST_METHOD(InsertTest1)
		{
			List<int> lst;
			lst.push_back(0);
			lst.push_back(1);
			lst.push_back(2);
			lst.insert(0, 21);
			Assert::IsTrue(lst.at(0) == 21, L"Assert 1");
			Assert::IsTrue(lst.at(1) == 0, L"Assert 2");
			Assert::IsTrue(lst.GetSize() == 4, L"Assert 3");
		}
		TEST_METHOD(InsertTest2)
		{
			List<int> lst;
			lst.insert(0, 21);
			Assert::IsTrue(lst.at(0) == 21, L"Assert 1");
			Assert::IsTrue(lst.GetSize() == 1, L"Assert 2");
		}
		TEST_METHOD(InsertTest3)
		{
			List<int> lst;
			lst.push_back(0);
			lst.push_back(1);
			lst.push_back(2);
			lst.insert(2, 21);
			Assert::IsTrue(lst.at(2) == 21, L"Assert 1");
			Assert::IsTrue(lst.at(3) == 2, L"Assert 2");
			Assert::IsTrue(lst.GetSize() == 4, L"Assert 3");
		}
		TEST_METHOD(InsertTest4)
		{
			List<int> lst;
			lst.push_back(0);
			lst.push_back(1);
			lst.push_back(2);
			lst.push_back(3);
			lst.push_back(4);
			lst.insert(2, 21);
			Assert::IsTrue(lst.at(2) == 21, L"Assert 1");
			Assert::IsTrue(lst.at(3) == 2, L"Assert 2");
			Assert::IsTrue(lst.GetSize() == 6, L"Assert 3");
		}
		TEST_METHOD(InsertTest5)
		{
			List<int> lst;
			lst.push_back(0);
			lst.push_back(1);
			try
			{
				lst.insert(-3, 21);
			}
			catch (const char* error)
			{
				Assert::AreEqual(error, "Error! Incorrect input.");
			}
		}
		TEST_METHOD(SetTest1)
		{
			List<int> lst;
			lst.push_back(0);
			lst.push_back(1);
			lst.push_back(2);
			lst.set(0, 21);
			Assert::IsTrue(lst.at(0) == 21, L"Assert 1");
			Assert::IsTrue(lst.at(1) == 1, L"Assert 2");
			Assert::IsTrue(lst.GetSize() == 3, L"Assert 3");
		}
		TEST_METHOD(SetTest2)
		{
			List<int> lst;
			lst.push_back(0);
			lst.push_back(1);
			lst.push_back(2);
			lst.push_back(3);
			lst.push_back(4);
			lst.push_back(5);
			lst.push_back(6);
			lst.push_back(7);
			lst.push_back(8);
			lst.set(2, 21);
			Assert::IsTrue(lst.at(2) == 21, L"Assert 1");
			Assert::IsTrue(lst.at(3) == 3, L"Assert 2");
			Assert::IsTrue(lst.GetSize() == 9, L"Assert 3");
		}
		TEST_METHOD(SetTest3)
		{
			List<int> lst;
			lst.push_back(0);
			lst.push_back(1);
			lst.push_back(2);
			lst.push_back(3);
			lst.push_back(4);
			lst.push_back(5);
			lst.push_back(6);
			lst.push_back(7);
			lst.push_back(8);
			lst.set(7, 21);
			Assert::IsTrue(lst.at(7) == 21, L"Assert 1");
			Assert::IsTrue(lst.at(8) == 8, L"Assert 2");
			Assert::IsTrue(lst.GetSize() == 9, L"Assert 3");
		}
		TEST_METHOD(SetTest4)
		{
			List<int> lst;
			lst.push_back(0);
			lst.push_back(1);
			lst.push_back(2);
			lst.push_back(3);
			lst.push_back(4);
			lst.push_back(5);
			lst.push_back(6);
			lst.push_back(7);
			lst.push_back(8);
			lst.set(8, 21);
			Assert::IsTrue(lst.at(8) == 21, L"Assert 1");
			Assert::IsTrue(lst.at(7) == 7, L"Assert 2");
			Assert::IsTrue(lst.GetSize() == 9, L"Assert 3");
		}
		TEST_METHOD(SetTest5)
		{
			List<int> lst;
			lst.push_back(0);
			lst.push_back(1);
			lst.push_back(2);
			try
			{
				lst.set(-3, 21);
			}
			catch (const char* error)
			{
				Assert::AreEqual(error, "Error! Incorrect input.");
			}
		}
		TEST_METHOD(RemoveTest1)
		{
			List<int> lst;
			lst.push_back(0);
			lst.push_back(1);
			lst.remove(0);
			Assert::IsTrue(lst.at(0) == 1, L"Assert 1");
			Assert::IsTrue(lst.GetSize() == 1, L"Assert 2");
		}
		TEST_METHOD(RemoveTest2)
		{
			List<int> lst;
			lst.push_back(0);
			lst.push_back(1);
			lst.push_back(2);
			lst.push_back(3);
			lst.push_back(4);
			lst.push_back(5);
			lst.push_back(6);
			lst.push_back(7);
			lst.push_back(8);
			lst.remove(2);
			Assert::IsTrue(lst.at(2) == 3, L"Assert 1");
			Assert::IsTrue(lst.GetSize() == 8, L"Assert 2");
		}
		TEST_METHOD(RemoveTest3)
		{
			List<int> lst;
			lst.push_back(0);
			lst.push_back(1);
			lst.push_back(2);
			lst.push_back(3);
			lst.push_back(4);
			lst.push_back(5);
			lst.push_back(6);
			lst.push_back(7);
			lst.push_back(8);
			lst.remove(6);
			Assert::IsTrue(lst.at(6) == 7, L"Assert 1");
			Assert::IsTrue(lst.GetSize() == 8, L"Assert 2");
		}
		TEST_METHOD(RemoveTest4)
		{
			List<int> lst;
			lst.push_back(0);
			lst.push_back(1);
			lst.push_back(2);
			lst.push_back(3);
			lst.push_back(4);
			lst.push_back(5);
			lst.remove(5);
			Assert::IsTrue(lst.at(4) == 4, L"Assert 1");
			Assert::IsTrue(lst.GetSize() == 5, L"Assert 2");
		}
		TEST_METHOD(RemoveTest5)
		{
			List<int> lst;
			lst.push_back(0);
			lst.push_back(1);
			lst.push_back(2);
			try
			{
				lst.remove(-2);
			}
			catch (const char* error)
			{
				Assert::AreEqual(error, "Error! Incorrect input.");
			}
		}
	};
	TEST_CLASS(GraphTest)
	{
	public:

		TEST_METHOD(GetValueTest)
		{
			int dim = 3;
			Graph Test(dim);
			Assert::IsTrue(Test.GetValue(0, 1) == 0);
		}
		TEST_METHOD(SetValueTest)
		{
			int dim = 3;
			Graph Test(dim);
			Test.SetValue(2, 2, 5);
			Assert::IsTrue(Test.GetValue(2, 2) == 5);
		}
		TEST_METHOD(BFSTest)
		{
			int dim = 3;
			Graph* Test = new Graph(dim);
			Graph* Flow = new Graph(3);
			Test->SetValue(0, 1, 1);
			Test->SetValue(0, 2, 1);
			Test->SetValue(1, 2, 1);
			Assert::IsTrue(Test->BFS(*Flow)->at(0) == 0);
			Assert::IsTrue(Test->BFS(*Flow)->at(1) == 2);
		}
	};
	TEST_CLASS(EdmondsKarpTest)
	{
	public:
		TEST_METHOD(SearchUniqueVertexesTest)
		{
			ifstream read("D:\\Программирование\\4 сем\\сourse\\Course_Work\\input.txt");
			if (!read.is_open())
				return;
			int VertexesNumber = 0;
			string UniqueVertexes = "";
			SearchUniqueVertexes(UniqueVertexes, VertexesNumber, read);
			VertexesNumber = VertexesNumber - 1;
			char* Vertexes = new char[VertexesNumber];
			for (int k = 0; k < VertexesNumber; ++k)
				Vertexes[k] = UniqueVertexes[k];
			read.close();
			Assert::IsTrue(Vertexes[0] == 'S');
			Assert::IsTrue(Vertexes[1] == 'O');
			Assert::IsTrue(Vertexes[2] == 'P');
			Assert::IsTrue(Vertexes[3] == 'Q');
			Assert::IsTrue(Vertexes[4] == 'R');
			Assert::IsTrue(Vertexes[5] == 'T');
			Assert::IsTrue(VertexesNumber == 6);
			delete[] Vertexes;
		}
		TEST_METHOD(EdmondsKarpTest_1)
		{
			ifstream read("D:\\Программирование\\4 сем\\сourse\\Course_Work\\input.txt");
			if (!read.is_open())
				return;
			unsigned MaxFlow = 0;
			Process(MaxFlow, read);
			read.close();
			Assert::IsTrue(MaxFlow == 5);
		}
		TEST_METHOD(EdmondsKarpTest_2)
		{
			ifstream read("D:\\Программирование\\4 сем\\сourse\\Course_Work\\test.txt");
			if (!read.is_open())
				return;
			unsigned MaxFlow = 0;
			Process(MaxFlow, read);
			read.close();
			Assert::IsTrue(MaxFlow == 14);
		}
	};
}
