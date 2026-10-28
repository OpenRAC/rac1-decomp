#ifndef RECORDS_H
#define RECORDS_H

/* Small records many level files read through the same layout. */

/* A function-pointer dispatch entry (0x14 bytes) in the camera and mode tables. */
typedef struct {
    char unk_00[8];
    void (*fn_08)(void *);
    char unk_0C[4];
    void (*fn_10)(void *);
} DispatchRec;

/* The slot tables of the pad-driven selector state at D_001A01F0. */
typedef struct {
    int _pad0[0x9E];
    int use[5];
    int flags[5];
    int sel;
    int size[5];
} PadSlots;

/* An animation sequence header: only the frame count is read. */
typedef struct {
    char _pad00[0x10];
    unsigned char nframes;
} AnimSeq;

/* Vendor item pricing and ammo capacity records (D_001E02B0). */
typedef struct VendorItemPrice {
    s32 price;            /* 0x00: item purchase price */
    s32 discount_price;   /* 0x04: discount price (Persuader) */
    u16 ammo_price;       /* 0x08: price per ammo round */
    u16 ammo_price_alt;   /* 0x0A */
    u8 pad_0C[2];         /* 0x0C */
    u16 max_ammo;         /* 0x0E: maximum ammo capacity */
    u8 pad_10[8];         /* 0x10 */
} VendorItemPrice;

/* Level collectible/save state (gold bolts, level-specific items). */
typedef struct {
    u8 pad0[0x454];
    u8 collected[1];
} LevelState;

#endif /* RECORDS_H */
