#include <stdio.h>
#include <stdlib.h>
#include "ssd.h"

unsigned int Get_Region(struct ssd_info *ssd, struct local *location);
void Set_Region(struct ssd_info *ssd, struct local *location, unsigned int region);

unsigned int Hotness_DAC(struct ssd_info *ssd, struct local *location);
void Write_DAC(struct ssd_info *ssd, unsigned int lpn);
