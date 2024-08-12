// Set the first 8kb prg bank
void __fastcall__ mmc3_set_prg_bank_0(unsigned char bank);
// Set the second 8kb prg bank
void __fastcall__ mmc3_set_prg_bank_1(unsigned char bank);
// Set the first 2kb chr bank
void __fastcall__ mmc3_set_2kb_chr_bank_0(unsigned char bank);
// Set the second 2kb chr bank
void __fastcall__ mmc3_set_2kb_chr_bank_1(unsigned char bank);
// Set the first 1kb chr bank
void __fastcall__ mmc3_set_1kb_chr_bank_0(unsigned char bank);
// Set the second 1kb chr bank
void __fastcall__ mmc3_set_1kb_chr_bank_1(unsigned char bank);
// Set the third 1kb chr bank
void __fastcall__ mmc3_set_1kb_chr_bank_2(unsigned char bank);
// Set the fourth 1kb chr bank
void __fastcall__ mmc3_set_1kb_chr_bank_3(unsigned char bank);

// extern unsigned char MMC3_MIRRORING_VERTICAL;
// extern unsigned char MMC3_MIRRORING_HORIZONTAL;

// #define mmc3_set_mirroring(direction); \
// __asm__("LDA #%s", direction); \
// __asm__("STA MMC3_REG_MIRRORING");

extern unsigned char xargs[4];

void _mmc3_set_8kb_chr() {
    // bg
    mmc3_set_1kb_chr_bank_0(xargs[0]);
    mmc3_set_1kb_chr_bank_1(++xargs[0]);
    mmc3_set_1kb_chr_bank_2(++xargs[0]);
    mmc3_set_1kb_chr_bank_3(++xargs[0]);
	// sprites
	mmc3_set_2kb_chr_bank_0(xargs[0]+2);
    mmc3_set_2kb_chr_bank_1(xargs[0]+4);
}

#define mmc3_set_8kb_chr(bank) (xargs[0] = bank, _mmc3_set_8kb_chr())


// Turns off MMC3 irqs, and changes the array pointer
// to point to a default 0xff
void disable_irq(void);


// This points an array to the IRQ system 
// Also turns ON the system
void set_irq_ptr(uint8_t * address);


// Check if it's safe to write to the irq array
// returns 0xff if done, zero if not done
// if the irq pointer is pointing to 0xff it is
// safe to edit.
uint8_t is_irq_done(void);




// quick and easily write an irq table in ROM to the irq table in SRAM
void write_irq_table(uint8_t * data);