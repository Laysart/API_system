
undefined8 main(int param_1,long param_2)

{
  uint16_t uVar1;
  int iVar2;
  uint32_t uVar3;
  undefined8 uVar4;
  long in_FS_OFFSET;
  byte local_2b;
  short local_2a;
  undefined4 local_28;
  int local_24;
  undefined4 local_1e;
  undefined2 local_1a;
  byte *local_18;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_24 = shm_open("eXchange",0x42,0x1ff);
  if (local_24 == -1) {
    puts("shm_open - ERROR");
    uVar4 = 0xffffffff;
  }
  else {
    iVar2 = ftruncate(local_24,0x400);
    if (iVar2 == 0) {
      local_18 = (byte *)mmap((void *)0x0,0x400,3,1,local_24,0);
      if (local_18 == (byte *)0xffffffffffffffff) {
        puts("mmap - ERROR");
        uVar4 = 0xffffffff;
      }
      else {
        memset(local_18,0,0x400);
        if ((param_1 == 2) && (iVar2 = strcmp(*(char **)(param_2 + 8),"DEADCAFE"), iVar2 == 0)) {
          local_2b = 1;
          CodeBanner();
          do {
            while (*local_18 != 0) {
              sleep(1);
            }
            printf("Code? ");
            __isoc99_scanf(&DAT_001012c0,&local_2b);
            switch(local_2b) {
            default:
              local_2b = 7;
              break;
            case 1:
              printf("sz> ");
              __isoc99_scanf(&DAT_001012ca,local_18 + 1);
              break;
            case 2:
              printf("ile> ");
              __isoc99_scanf(&DAT_001012d3,&local_28);
              *(undefined4 *)(local_18 + 1) = local_28;
              break;
            case 3:
              printf("ibe> ");
              __isoc99_scanf(&DAT_001012d3,&local_28);
              *(undefined4 *)(local_18 + 1) = local_28;
              break;
            case 4:
              printf("sle> ");
              __isoc99_scanf(&DAT_001012e2,&local_2a);
              *(int *)(local_18 + 1) = (int)local_2a;
              break;
            case 5:
              printf("sbe> ");
              __isoc99_scanf(&DAT_001012e2,&local_2a);
              *(int *)(local_18 + 1) = (int)local_2a;
              break;
            case 6:
              printf("s> ");
              __isoc99_scanf(&DAT_001012e2,&local_1e);
              printf("i> ");
              __isoc99_scanf(&DAT_001012d3,(long)&local_1e + 2);
              *(undefined4 *)(local_18 + 1) = local_1e;
              *(undefined2 *)(local_18 + 5) = local_1a;
            }
            *local_18 = local_2b;
          } while (local_2b < 7);
        }
        else {
          ReaderBanner();
          CodeBanner();
          do {
            memset(local_18,0,0x400);
            while (*local_18 == 0) {
              sleep(1);
            }
            switch(*local_18) {
            case 1:
              printf("-- %s --\n",local_18 + 1);
              break;
            case 2:
              printf("-- %08X --\n",(ulong)*(uint *)(local_18 + 1));
              break;
            case 3:
              uVar3 = htonl(*(uint32_t *)(local_18 + 1));
              printf("-- %08X --\n",(ulong)uVar3);
              break;
            case 4:
              printf("-- %04X --\n",(ulong)*(ushort *)(local_18 + 1));
              break;
            case 5:
              uVar1 = htons(*(uint16_t *)(local_18 + 1));
              printf("-- %04X --\n",(ulong)uVar1);
              break;
            case 6:
              printf("-- %04X - %08X --\n",(ulong)*(ushort *)(local_18 + 1),
                     (ulong)*(uint *)(local_18 + 3));
              break;
            default:
              puts("BYE...");
            }
          } while (*local_18 != 7);
        }
        iVar2 = munmap(local_18,0x400);
        if (iVar2 != 0) {
          puts("munmap - ERROR");
        }
        if ((param_1 == 1) && (iVar2 = shm_unlink("eXchange"), iVar2 != 0)) {
          puts("shm_unlink - ERROR");
        }
        uVar4 = 0;
      }
    }
    else {
      puts("ftruncate - ERROR");
      uVar4 = 0xffffffff;
    }
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

