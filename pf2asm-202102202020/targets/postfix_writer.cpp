#include <sstream>
#include "targets/postfix_writer.h"
#include "ast/all.h"

// must come after other #includes
#include "pf2asm_parser.tab.h"   /* token-based constants (from .y) */

//---------------------------------------------------------------------------
//     POSTFIX COMMANDS
//---------------------------------------------------------------------------

void pf2asm::postfix_writer::do_BSS(pf2asm::BSS *node, int level) {
  _pf.BSS();
}
void pf2asm::postfix_writer::do_DATA(pf2asm::DATA *node, int level) {
  _pf.DATA();
}
void pf2asm::postfix_writer::do_RODATA(pf2asm::RODATA *node, int level) {
  _pf.RODATA();
}
void pf2asm::postfix_writer::do_TEXT(pf2asm::TEXT *node, int level) {
  _pf.TEXT();
}

void pf2asm::postfix_writer::do_SBYTE(pf2asm::SBYTE *node, int level) {
  _pf.SBYTE(node->value());
}
void pf2asm::postfix_writer::do_SSHORT(pf2asm::SSHORT *node, int level) {
  _pf.SSHORT(node->value());
}
void pf2asm::postfix_writer::do_SINT(pf2asm::SINT *node, int level) {
  _pf.SINT(node->value());
}
void pf2asm::postfix_writer::do_SFLOAT(pf2asm::SFLOAT *node, int level) {
  _pf.SFLOAT(node->value());
}
void pf2asm::postfix_writer::do_SDOUBLE(pf2asm::SDOUBLE *node, int level) {
  _pf.SDOUBLE(node->value());
}
void pf2asm::postfix_writer::do_SSTRING(pf2asm::SSTRING *node, int level) {
  _pf.SSTRING(node->value());
}
void pf2asm::postfix_writer::do_SALLOC(pf2asm::SALLOC *node, int level) {
  _pf.SALLOC(node->value());
}
void pf2asm::postfix_writer::do_SADDR(pf2asm::SADDR *node, int level) {
  _pf.SADDR(node->value());
}

void pf2asm::postfix_writer::do_ALIGN(pf2asm::ALIGN *node, int level) {
  _pf.ALIGN();
}
void pf2asm::postfix_writer::do_LABEL(pf2asm::LABEL *node, int level) {
  _pf.LABEL(node->label());
}
void pf2asm::postfix_writer::do_EXTERN(pf2asm::EXTERN *node, int level) {
  _pf.EXTERN(node->label());
}
void pf2asm::postfix_writer::do_GLOBAL(pf2asm::GLOBAL *node, int level) {
  _pf.GLOBAL(node->label(), (node->type() == "FUNC" ? _pf.FUNC() : _pf.OBJ()));
}

void pf2asm::postfix_writer::do_ADDR(pf2asm::ADDR *node, int level) {
  _pf.ADDR(node->label());
}
void pf2asm::postfix_writer::do_ADDRV(pf2asm::ADDRV *node, int level) {
  _pf.ADDRV(node->label());
}
void pf2asm::postfix_writer::do_ADDRA(pf2asm::ADDRA *node, int level) {
  _pf.ADDRA(node->label());
}
void pf2asm::postfix_writer::do_LOCAL(pf2asm::LOCAL *node, int level) {
  _pf.LOCAL(node->offset());
}
void pf2asm::postfix_writer::do_LOCA(pf2asm::LOCA *node, int level) {
  _pf.LOCA(node->offset());
}
void pf2asm::postfix_writer::do_LOCV(pf2asm::LOCV *node, int level) {
  _pf.LOCV(node->offset());
}

void pf2asm::postfix_writer::do_LDBYTE(pf2asm::LDBYTE *node, int level) {
  _pf.LDBYTE();
}
void pf2asm::postfix_writer::do_LDSHORT(pf2asm::LDSHORT *node, int level) {
  _pf.LDSHORT();
}
void pf2asm::postfix_writer::do_LDINT(pf2asm::LDINT *node, int level) {
  _pf.LDINT();
}
void pf2asm::postfix_writer::do_LDFLOAT(pf2asm::LDFLOAT *node, int level) {
  _pf.LDFLOAT();
}
void pf2asm::postfix_writer::do_LDDOUBLE(pf2asm::LDDOUBLE *node, int level) {
  _pf.LDDOUBLE();
}

void pf2asm::postfix_writer::do_STBYTE(pf2asm::STBYTE *node, int level) {
  _pf.STBYTE();
}
void pf2asm::postfix_writer::do_STSHORT(pf2asm::STSHORT *node, int level) {
  _pf.STSHORT();
}
void pf2asm::postfix_writer::do_STINT(pf2asm::STINT *node, int level) {
  _pf.STINT();
}
void pf2asm::postfix_writer::do_STFLOAT(pf2asm::STFLOAT *node, int level) {
  _pf.STFLOAT();
}
void pf2asm::postfix_writer::do_STDOUBLE(pf2asm::STDOUBLE *node, int level) {
  _pf.STDOUBLE();
}

void pf2asm::postfix_writer::do_SP(pf2asm::SP *node, int level) {
  _pf.SP();
}
void pf2asm::postfix_writer::do_ALLOC(pf2asm::ALLOC *node, int level) {
  _pf.ALLOC();
}
void pf2asm::postfix_writer::do_DUP32(pf2asm::DUP32 *node, int level) {
  _pf.DUP32();
}
void pf2asm::postfix_writer::do_DUP64(pf2asm::DUP64 *node, int level) {
  _pf.DUP64();
}
void pf2asm::postfix_writer::do_SWAP32(pf2asm::SWAP32 *node, int level) {
  _pf.SWAP32();
}
void pf2asm::postfix_writer::do_SWAP64(pf2asm::SWAP64 *node, int level) {
  _pf.SWAP64();
}
void pf2asm::postfix_writer::do_INT(pf2asm::INT *node, int level) {
  _pf.INT(node->value());
}
void pf2asm::postfix_writer::do_FLOAT(pf2asm::FLOAT *node, int level) {
  _pf.FLOAT(node->value());
}
void pf2asm::postfix_writer::do_DOUBLE(pf2asm::DOUBLE *node, int level) {
  _pf.DOUBLE(node->value());
}

void pf2asm::postfix_writer::do_NEG(pf2asm::NEG *node, int level) {
  _pf.NEG();
}
void pf2asm::postfix_writer::do_ADD(pf2asm::ADD *node, int level) {
  _pf.ADD();
}
void pf2asm::postfix_writer::do_SUB(pf2asm::SUB *node, int level) {
  _pf.SUB();
}
void pf2asm::postfix_writer::do_MUL(pf2asm::MUL *node, int level) {
  _pf.MUL();
}
void pf2asm::postfix_writer::do_DIV(pf2asm::DIV *node, int level) {
  _pf.DIV();
}
void pf2asm::postfix_writer::do_UDIV(pf2asm::UDIV *node, int level) {
  _pf.UDIV();
}
void pf2asm::postfix_writer::do_MOD(pf2asm::MOD *node, int level) {
  _pf.MOD();
}
void pf2asm::postfix_writer::do_UMOD(pf2asm::UMOD *node, int level) {
  _pf.UMOD();
}

void pf2asm::postfix_writer::do_DNEG(pf2asm::DNEG *node, int level) {
  _pf.DNEG();
}
void pf2asm::postfix_writer::do_DADD(pf2asm::DADD *node, int level) {
  _pf.DADD();
}
void pf2asm::postfix_writer::do_DSUB(pf2asm::DSUB *node, int level) {
  _pf.DSUB();
}
void pf2asm::postfix_writer::do_DMUL(pf2asm::DMUL *node, int level) {
  _pf.DMUL();
}
void pf2asm::postfix_writer::do_DDIV(pf2asm::DDIV *node, int level) {
  _pf.DDIV();
}

void pf2asm::postfix_writer::do_INCR(pf2asm::INCR *node, int level) {
  _pf.INCR(node->value());
}
void pf2asm::postfix_writer::do_DECR(pf2asm::DECR *node, int level) {
  _pf.DECR(node->value());
}

void pf2asm::postfix_writer::do_D2F(pf2asm::D2F *node, int level) {
  _pf.D2F();
}
void pf2asm::postfix_writer::do_F2D(pf2asm::F2D *node, int level) {
  _pf.F2D();
}
void pf2asm::postfix_writer::do_D2I(pf2asm::D2I *node, int level) {
  _pf.D2I();
}
void pf2asm::postfix_writer::do_I2D(pf2asm::I2D *node, int level) {
  _pf.I2D();
}

void pf2asm::postfix_writer::do_EQ(pf2asm::EQ *node, int level) {
  _pf.EQ();
}
void pf2asm::postfix_writer::do_NE(pf2asm::NE *node, int level) {
  _pf.NE();
}

void pf2asm::postfix_writer::do_GT(pf2asm::GT *node, int level) {
  _pf.GT();
}
void pf2asm::postfix_writer::do_GE(pf2asm::GE *node, int level) {
  _pf.GE();
}
void pf2asm::postfix_writer::do_LE(pf2asm::LE *node, int level) {
  _pf.LE();
}
void pf2asm::postfix_writer::do_LT(pf2asm::LT *node, int level) {
  _pf.LT();
}

void pf2asm::postfix_writer::do_UGT(pf2asm::UGT *node, int level) {
  _pf.UGT();
}
void pf2asm::postfix_writer::do_UGE(pf2asm::UGE *node, int level) {
  _pf.UGE();
}
void pf2asm::postfix_writer::do_ULE(pf2asm::ULE *node, int level) {
  _pf.ULE();
}
void pf2asm::postfix_writer::do_ULT(pf2asm::ULT *node, int level) {
  _pf.ULT();
}

void pf2asm::postfix_writer::do_DCMP(pf2asm::DCMP *node, int level) {
  _pf.DCMP();
}

void pf2asm::postfix_writer::do_NOT(pf2asm::NOT *node, int level) {
  _pf.NOT();
}
void pf2asm::postfix_writer::do_AND(pf2asm::AND *node, int level) {
  _pf.AND();
}
void pf2asm::postfix_writer::do_OR(pf2asm::OR *node, int level) {
  _pf.OR();
}
void pf2asm::postfix_writer::do_XOR(pf2asm::XOR *node, int level) {
  _pf.XOR();
}

void pf2asm::postfix_writer::do_ROTL(pf2asm::ROTL *node, int level) {
  _pf.ROTL();
}
void pf2asm::postfix_writer::do_ROTR(pf2asm::ROTR *node, int level) {
  _pf.ROTR();
}
void pf2asm::postfix_writer::do_SHTL(pf2asm::SHTL *node, int level) {
  _pf.SHTL();
}
void pf2asm::postfix_writer::do_SHTRU(pf2asm::SHTRU *node, int level) {
  _pf.SHTRU();
}
void pf2asm::postfix_writer::do_SHTRS(pf2asm::SHTRS *node, int level) {
  _pf.SHTRS();
}

void pf2asm::postfix_writer::do_ENTER(pf2asm::ENTER *node, int level) {
  _pf.ENTER(node->value());
}
void pf2asm::postfix_writer::do_START(pf2asm::START *node, int level) {
  _pf.START();
}

void pf2asm::postfix_writer::do_STFVAL32(pf2asm::STFVAL32 *node, int level) {
  _pf.STFVAL32();
}
void pf2asm::postfix_writer::do_STFVAL64(pf2asm::STFVAL64 *node, int level) {
  _pf.STFVAL64();
}

void pf2asm::postfix_writer::do_LEAVE(pf2asm::LEAVE *node, int level) {
  _pf.LEAVE();
}

void pf2asm::postfix_writer::do_RET(pf2asm::RET *node, int level) {
  _pf.RET();
}
void pf2asm::postfix_writer::do_RETN(pf2asm::RETN *node, int level) {
  _pf.RETN(node->value());
}

void pf2asm::postfix_writer::do_CALL(pf2asm::CALL *node, int level) {
  _pf.CALL(node->label());
}

void pf2asm::postfix_writer::do_TRASH(pf2asm::TRASH *node, int level) {
  _pf.TRASH(node->value());
}

void pf2asm::postfix_writer::do_LDFVAL32(pf2asm::LDFVAL32 *node, int level) {
  _pf.LDFVAL32();
}
void pf2asm::postfix_writer::do_LDFVAL64(pf2asm::LDFVAL64 *node, int level) {
  _pf.LDFVAL64();
}

void pf2asm::postfix_writer::do_JMP(pf2asm::JMP *node, int level) {
  _pf.JMP(node->label());
}
void pf2asm::postfix_writer::do_LEAP(pf2asm::LEAP *node, int level) {
  _pf.LEAP();
}
void pf2asm::postfix_writer::do_BRANCH(pf2asm::BRANCH *node, int level) {
  _pf.BRANCH();
}

void pf2asm::postfix_writer::do_JZ(pf2asm::JZ *node, int level) {
  _pf.JZ(node->label());
}
void pf2asm::postfix_writer::do_JNZ(pf2asm::JNZ *node, int level) {
  _pf.JNZ(node->label());
}

void pf2asm::postfix_writer::do_JEQ(pf2asm::JEQ *node, int level) {
  _pf.JEQ(node->label());
}
void pf2asm::postfix_writer::do_JNE(pf2asm::JNE *node, int level) {
  _pf.JNE(node->label());
}

void pf2asm::postfix_writer::do_JGT(pf2asm::JGT *node, int level) {
  _pf.JGT(node->label());
}
void pf2asm::postfix_writer::do_JGE(pf2asm::JGE *node, int level) {
  _pf.JGE(node->label());
}
void pf2asm::postfix_writer::do_JLE(pf2asm::JLE *node, int level) {
  _pf.JLE(node->label());
}
void pf2asm::postfix_writer::do_JLT(pf2asm::JLT *node, int level) {
  _pf.JLT(node->label());
}

void pf2asm::postfix_writer::do_JUGT(pf2asm::JUGT *node, int level) {
  _pf.JUGT(node->label());
}
void pf2asm::postfix_writer::do_JUGE(pf2asm::JUGE *node, int level) {
  _pf.JUGE(node->label());
}
void pf2asm::postfix_writer::do_JULE(pf2asm::JULE *node, int level) {
  _pf.JULE(node->label());
}
void pf2asm::postfix_writer::do_JULT(pf2asm::JULT *node, int level) {
  _pf.JULT(node->label());
}

void pf2asm::postfix_writer::do_NIL(pf2asm::NIL *node, int level) {
  _pf.NIL();
}
void pf2asm::postfix_writer::do_NOP(pf2asm::NOP *node, int level) {
  _pf.NOP();
}

//---------------------------------------------------------------------------
//     C  D  K      N O D E S
//---------------------------------------------------------------------------

void pf2asm::postfix_writer::do_nil_node(cdk::nil_node * const node, int lvl) {
  //EMPTY
}
void pf2asm::postfix_writer::do_data_node(cdk::data_node * const node, int lvl) {
  throw 42;
}

void pf2asm::postfix_writer::do_double_node(cdk::double_node * const node, int lvl) {
  throw 42;
}
void pf2asm::postfix_writer::do_integer_node(cdk::integer_node * const node, int lvl) {
  throw 42;
}
void pf2asm::postfix_writer::do_string_node(cdk::string_node * const node, int lvl) {
  throw 42;
}

void pf2asm::postfix_writer::do_variable_node(cdk::variable_node * const node, int lvl) {
  throw 42;
}
void pf2asm::postfix_writer::do_rvalue_node(cdk::rvalue_node * const node, int lvl) {
  throw 42;
}
void pf2asm::postfix_writer::do_assignment_node(cdk::assignment_node * const node, int lvl) {
  throw 42;
}

void pf2asm::postfix_writer::do_neg_node(cdk::neg_node * const node, int lvl) {
  throw 42;
}
void pf2asm::postfix_writer::do_add_node(cdk::add_node * const node, int lvl) {
  throw 42;
}
void pf2asm::postfix_writer::do_div_node(cdk::div_node * const node, int lvl) {
  throw 42;
}
void pf2asm::postfix_writer::do_mod_node(cdk::mod_node * const node, int lvl) {
  throw 42;
}
void pf2asm::postfix_writer::do_mul_node(cdk::mul_node * const node, int lvl) {
  throw 42;
}
void pf2asm::postfix_writer::do_sub_node(cdk::sub_node * const node, int lvl) {
  throw 42;
}

void pf2asm::postfix_writer::do_not_node(cdk::not_node * const node, int lvl) {
  throw 42;
}
void pf2asm::postfix_writer::do_and_node(cdk::and_node * const node, int lvl) {
  throw 42;
}
void pf2asm::postfix_writer::do_or_node(cdk::or_node * const node, int lvl) {
  throw 42;
}

void pf2asm::postfix_writer::do_eq_node(cdk::eq_node * const node, int lvl) {
  throw 42;
}
void pf2asm::postfix_writer::do_ge_node(cdk::ge_node * const node, int lvl) {
  throw 42;
}
void pf2asm::postfix_writer::do_gt_node(cdk::gt_node * const node, int lvl) {
  throw 42;
}
void pf2asm::postfix_writer::do_le_node(cdk::le_node * const node, int lvl) {
  throw 42;
}
void pf2asm::postfix_writer::do_lt_node(cdk::lt_node * const node, int lvl) {
  throw 42;
}
void pf2asm::postfix_writer::do_ne_node(cdk::ne_node * const node, int lvl) {
  throw 42;
}

//---------------------------------------------------------------------------
//     T H E    E N D
//---------------------------------------------------------------------------
void pf2asm::postfix_writer::do_sequence_node(cdk::sequence_node * const node, int lvl) {
  for (size_t i = 0; i < node->size(); i++)
    node->node(i)->accept(this, lvl);
}

//---------------------------------------------------------------------------
//     T H E    E N D
//---------------------------------------------------------------------------
