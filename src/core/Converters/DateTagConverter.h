/*
 *  DateTagConverter.h
 *  ObjectCube
 *
 *  Created by Grímur Tómasson on 10.4.2010.
 *  Copyright 2010 Reykjavik University. All rights reserved.
 *
 */

#ifndef ObjectCube_DATE_TAG_CONVERTER_
#define ObjectCube_DATE_TAG_CONVERTER_

#include <memory>

#include "TagConverter.h"

namespace ObjectCube 
{	
	class DateTagDataAccess;
	
	class DateTagConverter : public TagConverter
	{
	protected:
		virtual std::shared_ptr<Tag> dataAccessToLogic_( const TagDataAccess* tagDA );
		virtual unique_ptr<TagDataAccess> logicToDataAccess_( const Tag* tag );
		
	};
}

#endif