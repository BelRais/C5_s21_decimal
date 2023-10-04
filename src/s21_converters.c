#include "math.h"
#include "s21_decimal.h"

int s21_get_float_exponent(float *src) {
  return ((*(int *)src & ~0b10000000000000000000000000000000) >> 23) - 127;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int err = 0;
  int sign = 0;
  if (src < 0) {
    src *= -1;
    sign = 1;
  }
  s21_init_decimal(dst);
  if (src != 0 && dst != NULL && src != NAN && src != INFINITY) {
    int scale = 0;
    int binExp = s21_get_float_exponent(&src);
    if (binExp > 95) err = 1;
    if (binExp < 95) {
      double p = (double)src;
      while (scale < 28 && (int)p / (int)pow(2, 21) == 0) {
        p *= 10;
        scale++;
      }
      p = round(p);
      if ((binExp > -94 && binExp < 96) && scale <= 28) {
        p = (float)p;
        while (fmod(p, 10) == 0 && scale > 0) {
          scale--;
          p /= 10;
        }
        float r = (float)p;
        binExp = s21_get_float_exponent(&r);
        s21_setBit(dst, binExp, 1);
        unsigned int fbits = *((unsigned int *)&r);
        for (unsigned int mask = 0x400000; mask; mask >>= 1) {
          binExp--;
          if (!!(fbits & mask)) s21_setBit(dst, binExp, 1);
        }
        s21_setSign(dst, sign);
        s21_setScale(dst, scale);
      } else {
        err = 1;
      }
    }
  } else {
    err = 1;
  }
  return err;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int err = 0;
  if (dst) {
    *dst = 0;
    for (int i = 0; i < 96; i++) {
      if (s21_getBit(src, i)) {
        *dst += pow(2, i);
      }
    }
    *dst /= pow(10, s21_getScale(src));
    if (s21_getSign(src)) *dst *= (-1);
  } else {
    err = 1;
  }
  return err;
}

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  s21_init_decimal(dst);
  if (src < 0) {  // Если отрицательное число, то в 31 бит записываем 1, делаем
                  // src полож
    src = (-1) * src;
    dst->bits[3] = dst->bits[3] | (1u << 31);
  }
  dst->bits[0] = src;  // добавляем полож src в bits[0];
  return 0;
}

int findFirstBit(s21_decimal dst) {
  int find = 0;
  for (int i = 95; i >= 0 && !find; i--) {
    if (s21_getBit(dst, i)) find = i;
  }
  return find;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int err = 0;
  if (findFirstBit(src) > 31)
    err = 1;
  else {
    *dst = 0;
    for (int i = 0; i < 96; i++) {
      if (s21_getBit(src, i)) *dst += pow(2, i);
    }
    if (s21_getSign(src)) *dst *= -1;
    *dst /= pow(10, (s21_getScale(src)));
  }
  return err;
}
