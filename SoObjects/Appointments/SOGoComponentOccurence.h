/* SOGoComponentOccurence.h - this file is part of SOGo
 * 
 * Copyright (C) 2008-2014 Inverse inc.
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This file is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef SOGOCOMPONENTOCCURENCE_H
#define SOGOCOMPONENTOCCURENCE_H

#import <SOGo/SOGoObject.h>

@class NSException;

@class iCalAlarm;
@class iCalCalendar;
@class iCalPerson;
@class iCalRepeatableEntityObject;
@class SOGoCalendarComponent;

@protocol SOGoComponentOccurence

- (iCalRepeatableEntityObject *) occurence;
- (void) setIsNew: (BOOL) newIsNew;
- (BOOL) isNew;

- (NSException *) changeParticipationStatus: (NSString *) newPartStat
                               withDelegate: (iCalPerson *) delegate
                                      alarm: (iCalAlarm *) alarm;

@end

@interface SOGoComponentOccurence : SOGoObject <SOGoComponentOccurence>
{
  iCalCalendar *parentCalendar;
  iCalRepeatableEntityObject *component;
  iCalRepeatableEntityObject *master;
  BOOL isNew;
}

+ (id) occurenceWithComponent: (iCalRepeatableEntityObject *) newComponent
	  withMasterComponent: (iCalRepeatableEntityObject *) newMaster
		  inContainer: (SOGoCalendarComponent *) newContainer;

- (void) setComponent: (iCalRepeatableEntityObject *) newComponent;
- (iCalRepeatableEntityObject *) masterComponent;
- (void) setMasterComponent: (iCalRepeatableEntityObject *) newMaster;

@end

#endif /* SOGOCOMPONENTOCCURENCE_H */
