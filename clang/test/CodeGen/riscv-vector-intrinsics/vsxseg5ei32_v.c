// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -fallow-half-arguments-and-returns -fnative-half-type -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

void test_vsxseg5ei32_v_i8mf8x5 (int8_t *base, vuint32mf2_t bindex, vint8mf8x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i8mf8x5
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i8mf4x5 (int8_t *base, vuint32m1_t bindex, vint8mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i8mf4x5
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i8mf2x5 (int8_t *base, vuint32m2_t bindex, vint8mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i8mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i8m1x5 (int8_t *base, vuint32m4_t bindex, vint8m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i8m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i16mf4x5 (int16_t *base, vuint32mf2_t bindex, vint16mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i16mf4x5
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i16mf2x5 (int16_t *base, vuint32m1_t bindex, vint16mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i16mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i16m1x5 (int16_t *base, vuint32m2_t bindex, vint16m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i16m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i32mf2x5 (int32_t *base, vuint32mf2_t bindex, vint32mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i32mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i32m1x5 (int32_t *base, vuint32m1_t bindex, vint32m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i32m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i64m1x5 (int64_t *base, vuint32mf2_t bindex, vint64m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i64m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u8mf8x5 (uint8_t *base, vuint32mf2_t bindex, vuint8mf8x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u8mf8x5
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u8mf4x5 (uint8_t *base, vuint32m1_t bindex, vuint8mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u8mf4x5
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u8mf2x5 (uint8_t *base, vuint32m2_t bindex, vuint8mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u8mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u8m1x5 (uint8_t *base, vuint32m4_t bindex, vuint8m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u8m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u16mf4x5 (uint16_t *base, vuint32mf2_t bindex, vuint16mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u16mf4x5
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u16mf2x5 (uint16_t *base, vuint32m1_t bindex, vuint16mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u16mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u16m1x5 (uint16_t *base, vuint32m2_t bindex, vuint16m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u16m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u32mf2x5 (uint32_t *base, vuint32mf2_t bindex, vuint32mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u32mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u32m1x5 (uint32_t *base, vuint32m1_t bindex, vuint32m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u32m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u64m1x5 (uint64_t *base, vuint32mf2_t bindex, vuint64m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u64m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_f16mf4x5 (float16_t *base, vuint32mf2_t bindex, vfloat16mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_f16mf4x5
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_f16mf2x5 (float16_t *base, vuint32m1_t bindex, vfloat16mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_f16mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_f16m1x5 (float16_t *base, vuint32m2_t bindex, vfloat16m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_f16m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_f32mf2x5 (float32_t *base, vuint32mf2_t bindex, vfloat32mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_f32mf2x5
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_f32m1x5 (float32_t *base, vuint32m1_t bindex, vfloat32m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_f32m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_f64m1x5 (float64_t *base, vuint32mf2_t bindex, vfloat64m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_f64m1x5
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i8mf8x5_m (vbool64_t mask, int8_t *base, vuint32mf2_t bindex, vint8mf8x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i8mf8x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i8mf4x5_m (vbool32_t mask, int8_t *base, vuint32m1_t bindex, vint8mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i8mf4x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i8mf2x5_m (vbool16_t mask, int8_t *base, vuint32m2_t bindex, vint8mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i8mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i8m1x5_m (vbool8_t mask, int8_t *base, vuint32m4_t bindex, vint8m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i8m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i16mf4x5_m (vbool64_t mask, int16_t *base, vuint32mf2_t bindex, vint16mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i16mf4x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i16mf2x5_m (vbool32_t mask, int16_t *base, vuint32m1_t bindex, vint16mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i16mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i16m1x5_m (vbool16_t mask, int16_t *base, vuint32m2_t bindex, vint16m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i16m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i32mf2x5_m (vbool64_t mask, int32_t *base, vuint32mf2_t bindex, vint32mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i32mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i32m1x5_m (vbool32_t mask, int32_t *base, vuint32m1_t bindex, vint32m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i32m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_i64m1x5_m (vbool64_t mask, int64_t *base, vuint32mf2_t bindex, vint64m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_i64m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u8mf8x5_m (vbool64_t mask, uint8_t *base, vuint32mf2_t bindex, vuint8mf8x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u8mf8x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u8mf4x5_m (vbool32_t mask, uint8_t *base, vuint32m1_t bindex, vuint8mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u8mf4x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u8mf2x5_m (vbool16_t mask, uint8_t *base, vuint32m2_t bindex, vuint8mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u8mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u8m1x5_m (vbool8_t mask, uint8_t *base, vuint32m4_t bindex, vuint8m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u8m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u16mf4x5_m (vbool64_t mask, uint16_t *base, vuint32mf2_t bindex, vuint16mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u16mf4x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u16mf2x5_m (vbool32_t mask, uint16_t *base, vuint32m1_t bindex, vuint16mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u16mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u16m1x5_m (vbool16_t mask, uint16_t *base, vuint32m2_t bindex, vuint16m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u16m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u32mf2x5_m (vbool64_t mask, uint32_t *base, vuint32mf2_t bindex, vuint32mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u32mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u32m1x5_m (vbool32_t mask, uint32_t *base, vuint32m1_t bindex, vuint32m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u32m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_u64m1x5_m (vbool64_t mask, uint64_t *base, vuint32mf2_t bindex, vuint64m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_u64m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_f16mf4x5_m (vbool64_t mask, float16_t *base, vuint32mf2_t bindex, vfloat16mf4x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_f16mf4x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_f16mf2x5_m (vbool32_t mask, float16_t *base, vuint32m1_t bindex, vfloat16mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_f16mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_f16m1x5_m (vbool16_t mask, float16_t *base, vuint32m2_t bindex, vfloat16m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_f16m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_f32mf2x5_m (vbool64_t mask, float32_t *base, vuint32mf2_t bindex, vfloat32mf2x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_f32mf2x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_f32m1x5_m (vbool32_t mask, float32_t *base, vuint32m1_t bindex, vfloat32m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_f32m1x5_m
  // CHECK: ret void
  return;
}

void test_vsxseg5ei32_v_f64m1x5_m (vbool64_t mask, float64_t *base, vuint32mf2_t bindex, vfloat64m1x5_t value) {
  // CHECK-LABEL: test_vsxseg5ei32_v_f64m1x5_m
  // CHECK: ret void
  return;
}

