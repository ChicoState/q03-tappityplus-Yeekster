/**
 * Unit Test suite
**/

#include <gtest/gtest.h>
#include "tappity.h"
 
class tappityTest : public ::testing::Test
{
	protected:
		tappityTest(){} 
		virtual ~tappityTest(){} 
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(tappityTest, justTesting100){
	tappity myTap("A string thing that was inputted.");
	myTap.entry("A string thing that was inputted.");
	int acc = myTap.accuracy();
	ASSERT_EQ(acc, 100);
}

TEST(tappityTest, justTestingWithEmpty100){
	tappity myTap("");
	myTap.entry("");
	int acc = myTap.accuracy();
	ASSERT_EQ(acc, 100);
}

TEST(tappityTest, compareEmptyToOne){
	tappity myTap("");
	myTap.entry("1");
	int acc = myTap.accuracy();
	ASSERT_EQ(acc, 0);
}

TEST(tappityTest, compareOneToEmpty){
	tappity myTap("1");
	myTap.entry("");
	int acc = myTap.accuracy();
	ASSERT_EQ(acc, 0);
}

TEST(tappityTest, compareAlmostMatching){
	std::string ref = "Almost str";
	std::string input = "almost str";
	tappity myTap(ref);
	myTap.entry(input);
	int acc = myTap.accuracy();
	ASSERT_EQ(acc, 90);
}

TEST(tappityTest, lenDiff){
	tappity myTap("a string");
	myTap.entry("Another string");
	int ld = myTap.length_difference();
	ASSERT_EQ(ld, 6);
}

TEST(tappityTest, lenDiffw_oInput){
	tappity myTap("a string");
	int ld = myTap.length_difference();
	ASSERT_EQ(ld, 8);
}

TEST(tappityTest, lenDiff0){
	tappity myTap("a string");
	myTap.entry("a gnirts");
	int ld = myTap.length_difference();
	ASSERT_EQ(ld, 0);
}

TEST(tappityTest, lenDiffLen0){
	tappity myTap("");
	myTap.entry("");
	int ld = myTap.length_difference();
	ASSERT_EQ(ld, 0);
}

TEST(tappityTest, lenDiffLen0Init){
	tappity myTap("");
	int ld = myTap.length_difference();
	ASSERT_EQ(ld, 0);
}

TEST(tappityTest, accAndLen){
	tappity myTap("");
	int ld = myTap.length_difference();
	int acc = myTap.accuracy();
	ASSERT_EQ(ld, 0);
	ASSERT_EQ(acc, 100);
}

TEST(tappityTest, accAndLenDiffRefLong){
	tappity myTap("One");
	int ld = myTap.length_difference();
	int acc = myTap.accuracy();
	ASSERT_EQ(ld, 3);
	ASSERT_EQ(acc, 0);
}

TEST(tappityTest, accAndLenDiffInpLong){
	tappity myTap("");
	myTap.entry("One");
	int ld = myTap.length_difference();
	int acc = myTap.accuracy();
	ASSERT_EQ(ld, 3);
	ASSERT_EQ(acc, 0);
}

TEST(tappityTest, noConstructorJustBranching){
	int a = 0;
	ASSERT_EQ(a, 0);
}