; RUN: llc -mtriple=riscv64 -mattr=+experimental-v -verify-machineinstrs < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare <vscale x 2 x float> @llvm.riscv.vload.f32(float*);
define <vscale x 2 x float> @vle32_v_f32m1(float* %0) {
entry:
; CHECK-LABEL: vle32_v_f32m1
; CHECK: vle32.v v16, (a0)
; CHECK: ret 
%a =  tail call <vscale x 2 x float> @llvm.riscv.vload.f32(float* %0)
ret <vscale x 2 x float> %a
}

declare void @llvm.riscv.vstore.f32(float*, <vscale x 2 x float>);
define void @vse32_v_f32m1(float* %0, <vscale x 2 x float> %1) {
entry:
; CHECK-LABEL: vse32_v_f32m1
; CHECK: vse32.v v16, (a0)
; CHECK: ret 
tail call void @llvm.riscv.vstore.f32(float* %0, <vscale x 2 x float> %1)
ret void
}