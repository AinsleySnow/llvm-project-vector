// RUN: %clang --target=riscv64-unknown-linux-elf -S -emit-llvm  %s -o - |  FileCheck %s
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <riscv_vector.h>


vint8m1_t  __attribute__((noinline)) testsub8(vint8m1_t value1, vint8m1_t value2) {
  return vsub_vv_i8m1(value1, value2);
}
//CHECK: %4 = call <vscale x 8 x i8> @llvm.riscv.vsub.vv.nxv8i8(<vscale x 8 x i8> %2, <vscale x 8 x i8> %3) #2

vint16m1_t  __attribute__((noinline)) testsub16(vint16m1_t value1, vint16m1_t value2) {
  return vsub_vv_i16m1(value1, value2);
}
//CHECK: %4 = call <vscale x 4 x i16> @llvm.riscv.vsub.vv.nxv4i16(<vscale x 4 x i16> %2, <vscale x 4 x i16> %3) #2

vint32m1_t  __attribute__((noinline)) testsub32(vint32m1_t value1, vint32m1_t value2) {
  return vsub_vv_i32m1(value1, value2);
}
//CHECK: %4 = call <vscale x 2 x i32> @llvm.riscv.vsub.vv.nxv2i32(<vscale x 2 x i32> %2, <vscale x 2 x i32> %3) #2

vint64m1_t  __attribute__((noinline)) testsub64(vint64m1_t value1, vint64m1_t value2) {
  return vsub_vv_i64m1(value1, value2);
}
//CHECK: %4 = call <vscale x 1 x i64> @llvm.riscv.vsub.vv.nxv1i64(<vscale x 1 x i64> %2, <vscale x 1 x i64> %3) #2

vfloat16m1_t  __attribute__((noinline)) testfsub16(vfloat16m1_t value1, vfloat16m1_t value2) {
  return vfsub_vv_f16m1(value1, value2);
}
//CHECK: %4 = call <vscale x 4 x half> @llvm.riscv.vfsub.vv.nxv4f16(<vscale x 4 x half> %2, <vscale x 4 x half> %3) #2

vfloat32m1_t  __attribute__((noinline)) testfsub32(vfloat32m1_t value1, vfloat32m1_t value2) {
  return vfsub_vv_f32m1(value1, value2);
}
//CHECK: %4 = call <vscale x 2 x float> @llvm.riscv.vfsub.vv.nxv2f32(<vscale x 2 x float> %2, <vscale x 2 x float> %3) #2

vfloat64m1_t  __attribute__((noinline)) testfsub64(vfloat64m1_t value1, vfloat64m1_t value2) {
  return vfsub_vv_f64m1(value1, value2);
}

//CHECK: %4 = call <vscale x 1 x double> @llvm.riscv.vfsub.vv.nxv1f64(<vscale x 1 x double> %2, <vscale x 1 x double> %3) #2
vuint8m1_t  __attribute__((noinline)) testusub8(vuint8m1_t value1, vuint8m1_t value2) {
  return vsub_vv_u8m1(value1, value2);
}

vuint16m1_t  __attribute__((noinline)) testusub16(vuint16m1_t value1, vuint16m1_t value2) {
  return vsub_vv_u16m1(value1, value2);
}

vuint32m1_t  __attribute__((noinline)) testusub32(vuint32m1_t value1, vuint32m1_t value2) {
  return vsub_vv_u32m1(value1, value2);
}

vuint64m1_t  __attribute__((noinline)) testusub64(vuint64m1_t value1, vuint64m1_t value2) {
  return vsub_vv_u64m1(value1, value2);
}
//CHECK:   %4 = call <vscale x 8 x i8> @llvm.riscv.vsub.vv.nxv8i8(<vscale x 8 x i8> %2, <vscale x 8 x i8> %3) #2
//CHECK:   %4 = call <vscale x 4 x i16> @llvm.riscv.vsub.vv.nxv4i16(<vscale x 4 x i16> %2, <vscale x 4 x i16> %3) #2
//CHECK:   %4 = call <vscale x 2 x i32> @llvm.riscv.vsub.vv.nxv2i32(<vscale x 2 x i32> %2, <vscale x 2 x i32> %3) #2
//CHECK:   %4 = call <vscale x 1 x i64> @llvm.riscv.vsub.vv.nxv1i64(<vscale x 1 x i64> %2, <vscale x 1 x i64> %3) #2

