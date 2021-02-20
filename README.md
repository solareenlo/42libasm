# libasm

## Instruction
### shr, sar

| ニーモニック | 動作                                                            |
|:------------:|-----------------------------------------------------------------|
|      shr     | logic shift (シフトしてできた端の空白は必ず 0 を挿入する)       |
|      sar     | arithmetic shift (シフトしても最も右端のビットの値が変化しない) |

### Logical operation

| ニーモニック | 動作                                                                     |
|:------------:|--------------------------------------------------------------------------|
|      and     | ビット毎の論理積 (両方が真で真)                                          |
|      or      | ビット毎の論理和 (どちらかが真で真)                                      |
|      xor     | ビット毎の排他的論理和 (異なれば真)                                      |
|     test     | ビット毎の論理積による比較 (結果をフラグに反映させる,演算結果は返さない)<br> レジスタの値が0かどうかを調べるには，test \<reg\>\<reg\> 命令を使うのが一般的|

### lea, move

| ニーモニック | 動作                                               |
|:------------:|----------------------------------------------------|
|      lea     | 実行アドレスの値そのものをレジスタに設定する       |
|     move     | 実行アドレスの内容をレジスタまたはメモリに書き込む |

## Directive
### db, dw, dd, dq

| Directive | Description                    |
|:---------:|--------------------------------|
| db        | bytes                          |
| dw        | words, equal to 2 bytes each   |
| dd        | double words, equal to 4 bytes |
| dq        | quad words, equal to 8 bytes   |

## Register

| Name     | Onother Name | Description                              |
|----------|--------------|------------------------------------------|
| r0       | rax          | 算術処理で accumulator として使われる    |
| r3       | rbx          | Base register                            |
| r1       | rcx          | ループの回数 (cycles) に使われる         |
| r2       | rdx          | 入出力処理の間，データ (data) を格納する |
| r4       | rsp          | Stack pointer                            |
| r5       | rbp          | Base pointer of stack frame              |
| r6       | rsi          | Source index                             |
| r7       | rdi          | Destination index                        |
| r8...r15 | なし         |                                          |

## Basic
### system call
1. rax register にシステムコールの番号を入れる．
2. 引数は，以下のレジスタに入れる．
    - rdi, rsi, rbx, r8, r9, r10
    - システムコールは 6 個を超える引数を受け取ることはできない．
3. system call を実行する．
- レジスタを初期化する順序は問わない．
- システムコール命令は，rcx と r11 の値を書き換える．
  - 理由は，後ほど．
- 関数のリターン値は，rax に入ってる．

### callee-saved register & caller-saved register
- Callee-saved register (呼び出し先退避レジスタ)
  - rbx, rbp, rsp, r12, r13, r14, r15
  - 呼び出された関数自身が退避/復旧するレジスタ．
- Caller-saved register (呼び出し元退避レジスタ)
  - rax, rcx, rdx, rsi, rdi, r8, r9, r10, r11
  - 関数を呼び出す側，呼び出し前に退避し，呼び出し後に復旧するレジスタ．

