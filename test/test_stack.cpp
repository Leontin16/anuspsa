#include <gtest.h>
#include "stacklist.h"
#include "stack.h"
#include "list.h"
#include "postfix_form.h"

TEST(AbstractStack, can_create_stack_with_positive_length) {
	ASSERT_NO_THROW(TStackList<int> s);
}
TEST(AbstractStack, can_create_copied_stack) {
	TStackList<int> s;
	ASSERT_NO_THROW(TStackList<int> s1(s));
}
TEST(AbstractStack, can_push_and_get_top_element) {
	TStackList<int> s;
	s.push(1);
	EXPECT_EQ(s.Top(), 1);
}
TEST(AbstractStack, new_stack_is_empty) {
	TStackList<int> s;
	ASSERT_TRUE(s.isEmpty());
}
TEST(AbstractStack, can_pop_and_element) {
	TStackList<int> s;
	s.push(1);
	s.pop();
	ASSERT_TRUE(s.isEmpty());
}
TEST(AbstractStack, copied_stack_is_equal_to_source_one) {
	TStackList<int> s;
	ASSERT_NO_THROW(TStackList<int> s1(s));
}
TEST(AbstractStack, cant_pop_from_empty_stack) {
	TStackList<int> s;
	ASSERT_ANY_THROW(s.pop());
}



TEST(AbstractStack, can_create_array_stack_with_positive_length) {
	ASSERT_NO_THROW(ArrayStack<int> s(3));
}
TEST(AbstractStack, cant_create_array_stack_with_negative_length) {
	ASSERT_ANY_THROW(ArrayStack<int> s(-2));
}
TEST(AbstractStack, can_create_copied_array_stack) {
	ArrayStack<int> s(2);
	ASSERT_NO_THROW(ArrayStack<int> s1(s));
}
TEST(AbstractStack, can_array_push_and_get_top_element) {
	ArrayStack<int> s(2);
	s.push(1);
	EXPECT_EQ(s.Top(), 1);
}
TEST(AbstractStack, new_array_stack_is_empty) {
	ArrayStack<int> s(2);
	ASSERT_TRUE(s.isEmpty());
}
TEST(AbstractStack, array_stack_is_full) {
	ArrayStack<int> s(2);
	for (int i = 0; i < 2; i++) {
		s.push(1);
	}
	ASSERT_TRUE(s.isFull());
}
TEST(AbstractStack, can_array_pop_and_element) {
	ArrayStack<int> s(2);
	s.push(1);
	s.pop();
	ASSERT_TRUE(s.isEmpty());
}
TEST(AbstractStack, copied_array_stack_is_equal_to_source_one) {
	ArrayStack<int> s(2);
	ASSERT_NO_THROW(ArrayStack<int> s1(s));
}
TEST(AbstractStack, cant_array_pop_from_empty_stack) {
	ArrayStack<int> s(2);
	ASSERT_ANY_THROW(s.pop());
}
TEST(AbstractStack, cant_array_push_from_full_stack) {
	ArrayStack<int> s(2);
	for (int i = 0; i < 2; i++) {
		s.push(1);
	}
	ASSERT_ANY_THROW(s.push(1));
}
