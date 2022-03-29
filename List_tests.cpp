// Project UID c1f28c309e55405daf00c565d57ff9ad

#include "List.h"
#include "unit_test_framework.h"

using namespace std;

// Add your test cases here

TEST(test_push_back_one_element) {
    List<int> list;
    list.push_back(5);
    ASSERT_TRUE(list.front() == 5);
    ASSERT_TRUE(list.back() == 5);
}

TEST(test_push_back_two_elements) {
    List<int> list;
    list.push_back(5);
    list.push_back(8);
    ASSERT_TRUE(list.front() == 5);
    ASSERT_TRUE(list.back() == 8);
}

TEST(test_push_back_three_elements) {
    List<int> list;
    list.push_back(5);
    list.push_back(8);
    list.push_back(3);
    ASSERT_TRUE(list.front() == 5);
    ASSERT_TRUE(list.back() == 3);
}

TEST(test_list_default_ctor_int) {
    List<int> empty_list;
    ASSERT_TRUE(empty_list.empty());
    ASSERT_TRUE(empty_list.size() == 0);
    ASSERT_FALSE(empty_list.size() != 0);
}

TEST(test_list_assignment_operator) {
    List<int> empty_list;
    ASSERT_TRUE(empty_list.empty());

    List<int> not_empty_list;
    not_empty_list.push_back(4);
    not_empty_list.push_back(1);

    empty_list = not_empty_list;
    ASSERT_TRUE(!empty_list.empty());
    ASSERT_TRUE(empty_list.size() == 2);
    ASSERT_FALSE(empty_list.size() != 2);
}

TEST(test_push_front) {
    List<int> list;
    list.push_front(5);
    ASSERT_TRUE(list.front() == 5);
    ASSERT_TRUE(list.back() == 5);
}

TEST(test_push_front_two_elements) {
    List<int> list;
    list.push_front(5);
    list.push_front(8);
    ASSERT_TRUE(list.front() == 8);
    ASSERT_TRUE(list.back() == 5);
}

TEST(test_push_front_three_elements_int) {
    List<int> list;
    list.push_front(5);
    list.push_front(8);
    list.push_front(3);
    ASSERT_TRUE(list.front() == 3);
    ASSERT_TRUE(list.back() == 5);
}

TEST(test_pop_front) {
    List<int> list;
    list.push_front(5);
    list.push_front(8);
    list.push_front(3);

    ASSERT_TRUE(list.front() == 3);
    ASSERT_TRUE(list.back() == 5);

    list.pop_front();
    ASSERT_TRUE(list.front() == 8);
    ASSERT_TRUE(list.back() == 5);

    list.pop_front();
    ASSERT_TRUE(list.front() == 5);
    ASSERT_TRUE(list.back() == 5);

    list.push_back(2);
    ASSERT_TRUE(list.front() == 5);
    ASSERT_TRUE(list.back() == 2);

    list.push_back(1);
    ASSERT_TRUE(list.front() == 5);
    ASSERT_TRUE(list.back() == 1);

    list.pop_front();
    ASSERT_TRUE(list.front() == 2);
    ASSERT_TRUE(list.back() == 1);
}

TEST(test_pop_back) {
    List<int> list;
    list.push_back(5);
    list.push_back(8);
    list.push_back(3);

    ASSERT_TRUE(list.front() == 5);
    ASSERT_TRUE(list.back() == 3);

    list.pop_back();
    ASSERT_TRUE(list.front() == 5);
    ASSERT_TRUE(list.back() == 8);

    list.pop_back();
    ASSERT_TRUE(list.front() == 5);
    ASSERT_TRUE(list.back() == 5);

    list.push_back(2);
    ASSERT_TRUE(list.front() == 5);
    ASSERT_TRUE(list.back() == 2);

    list.push_back(1);
    ASSERT_TRUE(list.front() == 5);
    ASSERT_TRUE(list.back() == 1);

    list.pop_back();
    ASSERT_TRUE(list.front() == 5);
    ASSERT_TRUE(list.back() == 2);
}

TEST(test_clear_empty_list) {
    List<int> empty_list;
    empty_list.clear();
    ASSERT_TRUE(empty_list.empty());
    ASSERT_TRUE(empty_list.size() == 0);
    ASSERT_FALSE(empty_list.size() != 0);
}

TEST(test_clear_push_front) {
    List<int> list;
    list.push_front(5);
    list.push_front(8);
    list.push_front(3);
    list.clear();
    ASSERT_TRUE(list.empty());
    ASSERT_TRUE(list.size() == 0);
    ASSERT_FALSE(list.size() != 0);
}

TEST(test_clear_push_back) {
    List<int> list;
    list.push_back(5);
    list.push_back(8);
    list.push_back(3);
    list.clear();
    ASSERT_TRUE(list.empty());
    ASSERT_TRUE(list.size() == 0);
    ASSERT_FALSE(list.size() != 0);
}

TEST(test_copy_constructor) {
    List<int> list1;
    list1.push_back(5);
    list1.push_back(8);
    list1.push_back(3);
    
    List<int> list2(list1);
    ASSERT_TRUE(list2.size() == list1.size());

    List<int>::Iterator i;
    List<int>::Iterator j;

    list1.push_back(6);

    ASSERT_TRUE(list1.size() == 4);
    ASSERT_TRUE(list2.size() == 3);

    list2.pop_back();
    ASSERT_TRUE(list1.size() == 4);
    ASSERT_TRUE(list2.size() == 2);
}

TEST(test_iterator_operators) {
    List<int> list;
    list.push_back(5);
    list.push_back(8);
    list.push_back(3);

    List<int>::Iterator i(list.begin());
    ++i;
    ASSERT_TRUE(*i == 8);

    --i;
    ASSERT_TRUE(*i == 5);
}

TEST(test_iterator_equals_basic) {
    List<int> list;
    list.push_back(5);
    list.push_back(8);
    list.push_back(3);

    List<int>::Iterator i(list.begin());
    ++i;
    List<int>::Iterator j(list.begin());
    ++j;
    ASSERT_TRUE(i == j);
    ASSERT_FALSE(i != j);

    --i;
    ASSERT_TRUE(i != j);
    ASSERT_FALSE(i == j);
}

TEST(test_iterator_equals_2) {
    List<int> list;
    list.push_back(5);
    list.push_back(8);
    list.push_back(3);
    list.push_back(8);

    List<int>::Iterator i(list.begin());
    List<int>::Iterator j(list.begin());

    ASSERT_TRUE(i == j);
    ASSERT_FALSE(i != j);
    ++i;
    ++j;
    ++j;
    ++j;
    ASSERT_TRUE(*i == *j);
    ASSERT_TRUE(i != j);
    ASSERT_FALSE(i == j);

    --i;
    --j;
    ASSERT_TRUE(i != j);
    ASSERT_FALSE(i == j);
}

TEST(test_iterator_begin_and_end_empty) {
    List<int> empty_list_1;
    List<int>::Iterator i(empty_list_1.begin());
}

TEST(test_iterator_begin_end) {
    List<int> list;
    list.push_back(5);
    list.push_back(8);
    list.push_back(3);
    List<int>::Iterator i(list.begin());

    ASSERT_TRUE(*i == 5);
}

TEST(test_iterator_erase_middle) {
    List<int> list;
    list.push_back(5);
    list.push_back(8);
    list.push_back(3);
    List<int>::Iterator i(list.begin());
    List<int>::Iterator j(list.begin());
    ++i;

    list.erase(i);

    ASSERT_TRUE(list.size() == 2);
    ASSERT_TRUE(*j == 5);

    ++j;
    ASSERT_TRUE(*j == 3);
}

TEST(test_iterator_erase_beginning) {
    List<int> list;
    list.push_back(5);
    list.push_back(8);
    list.push_back(3);
    List<int>::Iterator i1(list.begin());
    list.erase(i1);
    ASSERT_TRUE(list.size() == 2);

    List<int>::Iterator i2(list.begin());
    ASSERT_TRUE(*i2 == 8);

    ++i2;
    ASSERT_TRUE(*i2 == 3);
}

TEST(test_iterator_erase_end) {
    List<int> list;
    list.push_back(5);
    list.push_back(8);
    list.push_back(3);
    List<int>::Iterator i1(list.begin());
    ASSERT_TRUE(*i1 == 5);
    ++i1;
    ++i1;
    list.erase(i1);

    ASSERT_TRUE(list.size() == 2);

    List<int>::Iterator i2(list.begin());
    ASSERT_TRUE(*i2 == 5);
    ++i2;
    ASSERT_TRUE(*i2 == 8);
}

TEST(test_iterator_insert_beginning) {
    List<int> list;
    list.push_back(5);
    list.push_back(8);
    list.push_back(3);
    List<int>::Iterator i(list.begin());
    list.insert(i, 9);

    ASSERT_TRUE(list.size() == 4);
    ASSERT_TRUE(*i == 5);

    --i;
    ASSERT_TRUE(*i == 9);

    ++i;
    ASSERT_TRUE(*i == 5);
    ++i;
    ASSERT_TRUE(*i == 8);
    ++i;
    ASSERT_TRUE(*i == 3);
}

TEST(test_iterator_insert_middle) {
    List<int> list;
    list.push_back(5);
    list.push_back(8);
    list.push_back(3);
    List<int>::Iterator i(list.begin());
    ++i;
    list.insert(i, 6);
    ASSERT_TRUE(list.size() == 4);
    ASSERT_TRUE(*i == 8);

    --i;
    ASSERT_TRUE(*i == 6);

    ++i;
    ASSERT_TRUE(*i == 8);
    ++i;
    ASSERT_TRUE(*i == 3);
}

TEST(test_iterator_erase_one_element) {
    List<int> list;
    list.push_back(5);
    List<int>::Iterator i(list.begin());
    list.erase(i);

    ASSERT_TRUE(list.size() == 0);
}

TEST(test_iterator_erase_empty_list) {
    List<int> empty_list;
    empty_list.push_back(5);
    List<int>::Iterator i(empty_list.begin());
    empty_list.erase(i);

    ASSERT_TRUE(empty_list.size() == 0);
}

TEST(test_iterator_constructor) {
    List<int> list;
    list.push_back(5);
    List<int>::Iterator i;
}

TEST(test_iterator_assignment_operator) {
    List<int> list1;
    list1.push_back(5);
    list1.push_back(6);
    list1.push_back(7);

    List<int> list2;
    list2.push_back(4);
    list2.push_back(2);

    list2 = list1;

    List<int>::Iterator i1(list1.begin());
    List<int>::Iterator i2(list2.begin());

    ASSERT_TRUE(list1.size() == 3);
    ASSERT_TRUE(list2.size() == 3);
    ASSERT_TRUE(*i1 == 5);
    ASSERT_TRUE(*i2 == 5);
    
    ++i1;
    ++i2;
    ASSERT_TRUE(*i1 == 6);
    ASSERT_TRUE(*i2 == 6);

    list2.push_back(8);
    ASSERT_TRUE(list1.size() == 3);
    ASSERT_TRUE(list2.size() == 4);
}

/*
TEST(test_iterator_insert_end) {
    List<int> list;
    list.push_back(5);
    list.push_back(8);
    list.push_back(3);
    List<int>::Iterator i(list.end());
    list.insert(i, 7);
    ASSERT_TRUE(list.size() == 4);
    ASSERT_TRUE(*i == 7);

    --i;
    --i;
    --i;
    ASSERT_TRUE(*i == 5);
}
*/

/*
TEST(test_copy_constructor) {
    List<int> list1;
    list1.push_back(5);
    list1.push_back(8);
    list1.push_back(3);
    List<int> list2(list1);
    for (Iterator = first; Iterator = last; Iterator++) {
        ASSERT EQUAL();
    }
}
*/


TEST_MAIN()
