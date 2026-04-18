// Copyright 2025 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

std::string infx2pstfx(const std::string &inf) {
  std::string pstfx = "";
  TStack<char, 100> stack;
  std::map<char, int> prio;

  prio['('] = 0;
  prio[')'] = 0;
  prio['+'] = 1;
  prio['-'] = 1;
  prio['*'] = 2;
  prio['/'] = 2;

  bool last_was_digit = false;

  for (size_t i = 0; i < inf.length(); ++i) {
    char ch = inf[i];

    if (ch >= '0' && ch <= '9') {
      pstfx += ch;
      last_was_digit = true;
    } else {
      if (last_was_digit) {
        pstfx += ' ';
        last_was_digit = false;
      }

      if (ch == '(') {
        stack.push(ch);
      } else if (ch == ')') {
        while (!stack.isEmpty() && stack.get() != '(') {
          pstfx += stack.pop();
          pstfx += ' ';
        }
        if (!stack.isEmpty()) {
          stack.pop();
        }
      } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
        while (!stack.isEmpty() && prio[stack.get()] >= prio[ch]) {
          pstfx += stack.pop();
          pstfx += ' ';
        }
        stack.push(ch);
      }
    }
  }

  if (last_was_digit) {
    pstfx += ' ';
  }

  while (!stack.isEmpty()) {
    pstfx += stack.pop();
    pstfx += ' ';
  }

  if (!pstfx.empty() && pstfx[pstfx.length() - 1] == ' ') {
    pstfx.resize(pstfx.length() - 1);
  }

  return pstfx;
}

int eval(const std::string &pref) {
  TStack<int, 100> stack;
  int num = 0;
  bool is_parsing_num = false;

  for (size_t i = 0; i < pref.length(); ++i) {
    char ch = pref[i];

    if (ch >= '0' && ch <= '9') {
      num = num * 10 + (ch - '0');
      is_parsing_num = true;
    } else if (ch == ' ') {
      if (is_parsing_num) {
        stack.push(num);
        num = 0;
        is_parsing_num = false;
      }
    } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
      if (is_parsing_num) {
        stack.push(num);
        num = 0;
        is_parsing_num = false;
      }

      int val2 = stack.pop();
      int val1 = stack.pop();

      if (ch == '+') {
        stack.push(val1 + val2);
      } else if (ch == '-') {
        stack.push(val1 - val2);
      } else if (ch == '*') {
        stack.push(val1 * val2);
      } else if (ch == '/') {
        stack.push(val1 / val2);
      }
    }
  }

  if (is_parsing_num) {
    stack.push(num);
  }

  return stack.get();
}
