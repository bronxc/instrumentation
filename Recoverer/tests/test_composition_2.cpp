/*
 * test_composition.c
 *
 *  Created on: Mar 18, 2012
 *      Author: agustin
 */

class ClassA
{
public:
	void method1()
	{
		field1 = 0x11111111;
	}

	void method2()
	{
		field2 = 0x11111112;
	}

	void method3()
	{
		field3 = 0x11111113;
	}

	int method4()
	{
		return field1 + field2 + field3;
	}

private:
	int field1;
	int field2;
	int field3;
};

class ClassC
{
	int field1;
	int field2;

public:
	void method1()
	{
		field1 = 0x22222221;
	}

	void method2()
	{
		field2 = 0x22222222;
	}

	int method3()
	{
		return field1 + field2;
	}

};

class ClassB
{
public:
	int field1;
	int field2;

	ClassA a;
	ClassC c;

	int method()
	{
		field1 = 0x33333331;
		field2 = 0x33333332;
		return field1 + field2;
	}
};

int main(int argc, char **argv)
{
	// ClassA *a = new ClassA();
	// a->method1();

	ClassB *b = new ClassB();

	b->method();

	b->c.method1();
	//offsets[0]b->a.method1();
}
