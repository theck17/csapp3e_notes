/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：2.61.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-07-14 00:44:22
 *   Description   ：
 */

int main(){
  // A
  !~x;;
  // B
  !x;
  // C
  !~(x | ~0xff);
  // D
  !((x >> ((sizeof(int)-1) << 3)) & 0xff);
    return 0;
}
