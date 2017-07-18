/* Copyright 2017 Lanting Guo */
/** karatsuba algorithm for integer multiplication

*/
#include <cassert>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <stdexcept>
#include <memory>

using string = std::string;
using std::shared_ptr;
using std::make_shared;

void sameLength(shared_ptr<string> &A,  shared_ptr<string> &B) {
  int A_len = A->length(), B_len = B->length();
  int num_zero = B_len - A_len;
  if (num_zero > 0) {
    A.reset(new string(string(num_zero, '0') + *A));
  }
  if (num_zero < 0) {
    num_zero *= -1;
    B.reset(new string(string(num_zero, '0') + *B));
  }
}

// 0012 + 1234
string Add(string A, string B) {
  shared_ptr<string> pA = make_shared<string>(A);
  shared_ptr<string> pB = make_shared<string>(B);
  sameLength(pA, pB);
  A = *pA, B = *pB;
  string sum;
  bool flow = false;
  auto len = A.length();
  char tmp;
  for (size_t i = 0; i < len; i++) {
    tmp = A[len-1-i] - '0' + B[len-1-i] + flow;  // - '0' + '0';
    if (tmp > '9') {
      flow = true;
      tmp = tmp - '9' - 1 + '0';
    } else {
      flow = false;
    }
    sum.insert(0, 1, tmp);
  }
  if (flow) sum = '1' + sum;

  return sum;
}
string Sub(string A, string B) {  // assert A > B
  shared_ptr<string> pA = make_shared<string>(A);
  shared_ptr<string> pB = make_shared<string>(B);
  sameLength(pA, pB);
  A = *pA, B = *pB;

  string ret;
  bool underflow = false;
  auto len = A.length();
  char tmp;
  for (size_t i = 0; i < len; i++) {
    tmp = A[len-1-i] - B[len-1-i] + '0' - underflow;
    if (tmp < '0') {
      underflow = true;
      tmp = tmp + 10;
    } else {
      underflow = false;
    }
    ret.insert(0, 1, tmp);
  }

  return ret;
}
string Mul(string A, string B) {
  size_t len_A = A.length(), len_B = B.length();
  if (len_A == 0 || len_B == 0) throw std::invalid_argument(
          "argument can not be null string");
  if (len_A == 1 && len_B == 1) {
    int int_A = A[0] - '0';
    int int_B = B[0] - '0';
    return std::to_string(int_A*int_B);
  }

  // make sure len_A == len_B add zeros to the front
  shared_ptr<string> pA = make_shared<string>(A);
  shared_ptr<string> pB = make_shared<string>(B);
  sameLength(pA, pB);
  A = *pA, B = *pB;

  len_A = A.length();
  size_t mid = len_A / 2;
  string a, b, c, d;
  a = A.substr(0, mid), b = A.substr(mid, len_A);
  c = B.substr(0, mid), d = B.substr(mid, len_B);
  string ac = Mul(a, c);
  string bd = Mul(b, d);

  // (a+b)*(c+d) - ac - bd
  string ad_bc = Sub(Sub(Mul(Add(a, b), Add(c, d)), ac), bd);
  ad_bc += string(len_A-mid, '0');
  ac    += string(2*(len_A-mid), '0');
  return Add(Add(ac, bd), ad_bc);
}


int main(int argc, char *argv[]) {
  shared_ptr<string> a = make_shared<string>(
      "3141592653589793238462643383279502884197169399375105820974944592");
  shared_ptr<string> b = make_shared<string>(
      "2718281828459045235360287471352662497757247093699959574966967627");
  // std::cout << a.substr(0, 2) << std::endl;
  // a = make_shared<string>("90"), b = make_shared<string>("55");
  // a = make_shared<string>("9"), b = make_shared<string>("10");
  std::cout << "before func Add:" << *a << ' ' << *b << '\n';
  sameLength(a, b);
  std::cout << "After func sameLength:" << *a << ' ' << *b << '\n';
  std::cout << "Add: " << Add(*a, *b) << std::endl;
  std::cout << "Sub: " << Sub(*a, *b) << std::endl;
  auto  ret = Mul(*a, *b);
  //  assert(std::stoi(ret) == std::stoi(*a)*std::stoi(*b));
  std::cout << ret << std::endl;

  return 0;
}
