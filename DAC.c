/* 2022/8/4 downgrade region needed */

#include "DAC.h"

#define Region_Size 4



/*----------------------------------------------------------------------------------------------------------*/

unsigned int Get_Region(struct ssd_info *ssd, struct local *location){
    unsigned int region;
    region = ssd->channel_head[location->channel].chip_head[location->chip].die_head[location->die].plane_head[location->plane].blk_head[location->block].page_head[location->page].region;
    return region;
}

void Set_Region(struct ssd_info *ssd, struct local *location, unsigned int region){
    ssd->channel_head[location->channel].chip_head[location->chip].die_head[location->die].plane_head[location->plane].blk_head[location->block].page_head[location->page].region = region;
}

/*----------------------------------------------------------------------------------------------------------*/

unsigned int Hotness_DAC(struct ssd_info *ssd, struct local *location){
    unsigned int region;
    region = Get_Region(ssd, location);
    if(region > 0) region = region - 1;
    return region;
}

void Write_DAC(struct ssd_info *ssd, unsigned int lpn){

    unsigned int ppn, region;
    struct entry *p_map = ssd->dram->map->map_entry;
    struct local *location = NULL;

    // lpn ---> location 
    ppn = (p_map[lpn]).pn;
//	printf("ppn : %d\n",ppn);
	
    location = find_location(ssd,ppn);

    region = Get_Region(ssd, location);
    if(region < Region_Size-1){
        region = region + 1;
        Set_Region(ssd, location, region);
		printf("region = %d\n", ssd->channel_head[location->channel].chip_head[location->chip].die_head[location->die].plane_head[location->plane].blk_head[location->block].page_head[location->page].region);
    }
}

/*----------------------------------------------------------------------------------------------------------*/
