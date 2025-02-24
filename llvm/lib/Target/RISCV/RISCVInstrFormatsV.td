//===-- RISCVInstrFormatsV.td - RISCV V Instruction Formats --*- tablegen -*-=//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
//  This file describes the RISC-V V extension instruction formats.
//
//===----------------------------------------------------------------------===//

class RISCVVFormat<bits<3> val> {
  bits<3> Value = val;
}
def OPIVV : RISCVVFormat<0b000>;
def OPFVV : RISCVVFormat<0b001>;
def OPMVV : RISCVVFormat<0b010>;
def OPIVI : RISCVVFormat<0b011>;
def OPIVX : RISCVVFormat<0b100>;
def OPFVF : RISCVVFormat<0b101>;
def OPMVX : RISCVVFormat<0b110>;

class RISCVMOP<bits<2> val> {
  bits<2> Value = val;
}
def MOPLDUnitStride : RISCVMOP<0b00>;
def MOPLDStrided    : RISCVMOP<0b10>;
def MOPLDIndexed    : RISCVMOP<0b11>;

def MOPSTUnitStride   : RISCVMOP<0b00>;
def MOPSTIndexedUnord : RISCVMOP<0b01>;
def MOPSTStrided      : RISCVMOP<0b10>;
def MOPSTIndexedOrder : RISCVMOP<0b11>;

class RISCVLSUMOP<bits<5> val> {
  bits<5> Value = val;
}
def LUMOPUnitStride  : RISCVLSUMOP<0b00000>;
def LUMOPUnitStrideWholeReg : RISCVLSUMOP<0b01000>;
def LUMOPUnitStrideFF: RISCVLSUMOP<0b10000>;
def SUMOPUnitStride  : RISCVLSUMOP<0b00000>;
def SUMOPUnitStrideWholeReg : RISCVLSUMOP<0b01000>;

class RISCVAMOOP<bits<5> val> {
  bits<5> Value = val;
}
def AMOOPVamoSwap : RISCVAMOOP<0b00001>;
def AMOOPVamoAdd : RISCVAMOOP<0b00000>;
def AMOOPVamoXor : RISCVAMOOP<0b00100>;
def AMOOPVamoAnd : RISCVAMOOP<0b01100>;
def AMOOPVamoOr : RISCVAMOOP<0b01000>;
def AMOOPVamoMin : RISCVAMOOP<0b10000>;
def AMOOPVamoMax : RISCVAMOOP<0b10100>;
def AMOOPVamoMinu : RISCVAMOOP<0b11000>;
def AMOOPVamoMaxu : RISCVAMOOP<0b11100>;

class RISCVWidth<bits<4> val> {
  bits<4> Value = val;
}
def LSWidth8     : RISCVWidth<0b0000>;
def LSWidth16    : RISCVWidth<0b0101>;
def LSWidth32    : RISCVWidth<0b0110>;
def LSWidth64    : RISCVWidth<0b0111>;
def LSWidth128   : RISCVWidth<0b1000>;
def LSWidth256   : RISCVWidth<0b1101>;
def LSWidth512   : RISCVWidth<0b1110>;
def LSWidth1024  : RISCVWidth<0b1111>;
// defset list<RISCVWidth> AllSEW = {
//   LSWidth8, LSWidth16, LSWidth32, LSWidth64,
//   LSWidth64, LSWidth128, LSWidth256, LSWidth1024
// }

class RVInstSetVLi<dag outs, dag ins, string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatI> {
  bits<5> rs1;
  bits<5> rd;
  bits<11> vtypei;

  let Inst{31} = 0;
  let Inst{30-20} = vtypei;
  let Inst{19-15} = rs1;
  let Inst{14-12} = 0b111;
  let Inst{11-7} = rd;
  let Opcode = OPC_OP_V.Value;

  let Defs = [VTYPE, VL];
}

class RVInstSetVL<dag outs, dag ins, string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatR> {
  bits<5> rs2;
  bits<5> rs1;
  bits<5> rd;

  let Inst{31} = 1;
  let Inst{30-25} = 0b000000;
  let Inst{24-20} = rs2;
  let Inst{19-15} = rs1;
  let Inst{14-12} = 0b111;
  let Inst{11-7} = rd;
  let Opcode = OPC_OP_V.Value;

  let Defs = [VTYPE, VL];
}

class RVInstVV<bits<6> funct6, RISCVVFormat opv, dag outs, dag ins,
               string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatR> {
  bits<5> vs2;
  bits<5> vs1;
  bits<5> vd;
  bit vm;

  let Inst{31-26} = funct6;
  let Inst{25} = vm;
  let Inst{24-20} = vs2;
  let Inst{19-15} = vs1;
  let Inst{14-12} = opv.Value;
  let Inst{11-7} = vd;
  let Opcode = OPC_OP_V.Value;

  let Uses = [VTYPE, VL];
  let RVVConstraint = VMConstraint;
}

class RVInstVX<bits<6> funct6, RISCVVFormat opv, dag outs, dag ins,
                string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatR> {
  bits<5> vs2;
  bits<5> rs1;
  bits<5> vd;
  bit vm;

  let Inst{31-26} = funct6;
  let Inst{25} = vm;
  let Inst{24-20} = vs2;
  let Inst{19-15} = rs1;
  let Inst{14-12} = opv.Value;
  let Inst{11-7} = vd;
  let Opcode = OPC_OP_V.Value;

  let Uses = [VTYPE, VL];
  let RVVConstraint = VMConstraint;
}

class RVInstV2<bits<6> funct6, bits<5> vs2, RISCVVFormat opv, dag outs, dag ins,
                string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatR> {
  bits<5> rs1;
  bits<5> vd;
  bit vm;

  let Inst{31-26} = funct6;
  let Inst{25} = vm;
  let Inst{24-20} = vs2;
  let Inst{19-15} = rs1;
  let Inst{14-12} = opv.Value;
  let Inst{11-7} = vd;
  let Opcode = OPC_OP_V.Value;

  let Uses = [VTYPE, VL];
  let RVVConstraint = VMConstraint;
}

class RVInstIVI<bits<6> funct6, dag outs, dag ins, string opcodestr,
                string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatR> {
  bits<5> vs2;
  bits<5> imm;
  bits<5> vd;
  bit vm;

  let Inst{31-26} = funct6;
  let Inst{25} = vm;
  let Inst{24-20} = vs2;
  let Inst{19-15} = imm;
  let Inst{14-12} = 0b011;
  let Inst{11-7} = vd;
  let Opcode = OPC_OP_V.Value;

  let Uses = [VTYPE, VL];
  let RVVConstraint = VMConstraint;
}

class RVInstV<bits<6> funct6, bits<5> vs1, RISCVVFormat opv, dag outs,
              dag ins, string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatR> {
  bits<5> vs2;
  bits<5> vd;
  bit vm;

  let Inst{31-26} = funct6;
  let Inst{25} = vm;
  let Inst{24-20} = vs2;
  let Inst{19-15} = vs1;
  let Inst{14-12} = opv.Value;
  let Inst{11-7} = vd;
  let Opcode = OPC_OP_V.Value;

  let Uses = [VTYPE, VL];
  let RVVConstraint = VMConstraint;
}

class RVInstVLU<bits<3> nf, bit mew, RISCVLSUMOP lumop,
                bits<3> width, dag outs, dag ins, string opcodestr,
                string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatR> {
  bits<5> rs1;
  bits<5> vd;
  bit vm;

  let Inst{31-29} = nf;
  let Inst{28} = mew;
  let Inst{27-26} = MOPLDUnitStride.Value;
  let Inst{25} = vm;
  let Inst{24-20} = lumop.Value;
  let Inst{19-15} = rs1;
  let Inst{14-12} = width;
  let Inst{11-7} = vd;
  let Opcode = OPC_LOAD_FP.Value;

  let Uses = [VTYPE, VL];
  let RVVConstraint = VMConstraint;
}

class RVInstVLS<bits<3> nf, bit mew, bits<3> width,
                dag outs, dag ins, string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatR> {
  bits<5> rs2;
  bits<5> rs1;
  bits<5> vd;
  bit vm;

  let Inst{31-29} = nf;
  let Inst{28} = mew;
  let Inst{27-26} = MOPLDStrided.Value;
  let Inst{25} = vm;
  let Inst{24-20} = rs2;
  let Inst{19-15} = rs1;
  let Inst{14-12} = width;
  let Inst{11-7} = vd;
  let Opcode = OPC_LOAD_FP.Value;

  let Uses = [VTYPE, VL];
  let RVVConstraint = VMConstraint;
}

class RVInstVLX<bits<3> nf, bit mew, bits<3> width,
                dag outs, dag ins, string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatR> {
  bits<5> vs2;
  bits<5> rs1;
  bits<5> vd;
  bit vm;

  let Inst{31-29} = nf;
  let Inst{28} = mew;
  let Inst{27-26} = MOPLDIndexed.Value;
  let Inst{25} = vm;
  let Inst{24-20} = vs2;
  let Inst{19-15} = rs1;
  let Inst{14-12} = width;
  let Inst{11-7} = vd;
  let Opcode = OPC_LOAD_FP.Value;

  let Uses = [VTYPE, VL];
  let RVVConstraint = VMConstraint;
}

class RVInstVSU<bits<3> nf, bit mew, RISCVLSUMOP sumop,
                bits<3> width, dag outs, dag ins, string opcodestr,
                string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatR> {
  bits<5> rs1;
  bits<5> vs3;
  bit vm;

  let Inst{31-29} = nf;
  let Inst{28} = mew;
  let Inst{27-26} = MOPSTUnitStride.Value;
  let Inst{25} = vm;
  let Inst{24-20} = sumop.Value;
  let Inst{19-15} = rs1;
  let Inst{14-12} = width;
  let Inst{11-7} = vs3;
  let Opcode = OPC_STORE_FP.Value;

  let Uses = [VTYPE, VL];
}

class RVInstVSS<bits<3> nf, bit mew, bits<3> width,
                dag outs, dag ins, string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatR> {
  bits<5> rs2;
  bits<5> rs1;
  bits<5> vs3;
  bit vm;

  let Inst{31-29} = nf;
  let Inst{28} = mew;
  let Inst{27-26} = MOPSTStrided.Value;
  let Inst{25} = vm;
  let Inst{24-20} = rs2;
  let Inst{19-15} = rs1;
  let Inst{14-12} = width;
  let Inst{11-7} = vs3;
  let Opcode = OPC_STORE_FP.Value;

  let Uses = [VTYPE, VL];
}

class RVInstVSX<bits<3> nf, bit mew, RISCVMOP mop, bits<3> width,
                dag outs, dag ins, string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatR> {
  bits<5> vs2;
  bits<5> rs1;
  bits<5> vs3;
  bit vm;

  let Inst{31-29} = nf;
  let Inst{28} = mew;
  let Inst{27-26} = mop.Value;
  let Inst{25} = vm;
  let Inst{24-20} = vs2;
  let Inst{19-15} = rs1;
  let Inst{14-12} = width;
  let Inst{11-7} = vs3;
  let Opcode = OPC_STORE_FP.Value;

  let Uses = [VTYPE, VL];
}

class RVInstVAMO<RISCVAMOOP amoop, bits<3> width, dag outs, 
                 dag ins, string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatR> {
  bits<5> vs2;
  bits<5> rs1;
  bit wd;
  bit vm;

  let Inst{31-27} = amoop.Value;
  let Inst{26} = wd;
  let Inst{25} = vm;
  let Inst{24-20} = vs2;
  let Inst{19-15} = rs1;
  let Inst{14-12} = width;
  let Opcode = OPC_AMO.Value;

  let Uses = [VTYPE, VL];
}
