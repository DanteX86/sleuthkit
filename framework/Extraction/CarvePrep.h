/*
 * The Sleuth Kit
 *
 * Contact: Brian Carrier [carrier <at> sleuthkit [dot] org]
 * Copyright (c) 2010-2012 Basis Technology Corporation. All Rights
 * reserved.
 *
 * This software is distributed under the Common Public License 1.0
 */

#ifndef _TSK_CARVE_PREP_H
#define _TSK_CARVE_PREP_H

#include "Services/TskImgDB.h"

/**
 * Interface for class that prepares for later carving. 
 * CarvePrep is responsible for making unallocated sectors image files for 
 * later carving.  The implementation can choose to create 1 or dozens
 * of such files.  Refer to \ref fw_extract_carve for details,
 * but this class should get unallocated image IDs from TskImgDB,
 * populate the unalloc_alloc map in the database, and schedule
 * each unallocated image for later carving. 
 */
class TSK_FRAMEWORK_API CarvePrep
{
public:
    virtual ~CarvePrep(void) {}
    
    /**
     * Make one or more unallocated sectors image files to carve. 
     *
     * @param a_toSchedule True if the scheduler should be called to queue
     * up the output files or false if the files should be processed now.
     * @returns 0 on success, 1 on error. 
     */
    virtual int processSectors(bool a_toSchedule) = 0;
};

#endif