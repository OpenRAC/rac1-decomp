/* Data owned by src/core/sound/989snd.c. Its values come from your own baserom (tools/data_in_c.py). */
#include "common.h"

#include "structs/data/core_sound_989snd.h"

u32 snd_command_buffer1[1024] DATA_SECTION(D_00133380) = {0};

u32 snd_command_buffer2[1024] DATA_SECTION(D_00134380) = {0};

u32 snd_stream_buffer1[1024] DATA_SECTION(D_00135380) = {0};

u32 snd_stream_buffer2[1024] DATA_SECTION(D_00136380) = {0};

u32 snd_return_buffer1[272] DATA_SECTION(D_00137380) = {0};

u32 snd_return_buffer2[272] DATA_SECTION(D_001377C0) = {0};

CdSafeState sound_read_work[3] DATA_SECTION(D_00137C00) = {0};

u32 snd_cd_bank_load_request[16] DATA_SECTION(D_00137C40) = {0};
