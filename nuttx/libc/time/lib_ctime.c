/****************************************************************************
 * libc/time/lib_asctime.c
 *
 *   Copyright (C) 2015 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <time.h>

#ifdef CONFIG_TIME_EXTENDED

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Function:  ctime
 *
 * Description:
 *   ctime and ctime_r converts the time provided in seconds since the
 *   epoch to a string representation. asctime is not re-entrant. ctime is
 *   not re-entrant.
 *
 * Parameters:
 *   timep - The current time represented as seconds since the epoch.
 *
 * Return Value:
 *   One success a pointer to the string is returned; on failure, NULL is
 *   returned.
 *
 ****************************************************************************/

FAR char *ctime(FAR const time_t *timep)
{
#ifdef CONFIG_LIBC_LOCALTIME
  /* Section 4.12.3.2 of X3.159-1989 requires that
   *    The ctime function converts the calendar time pointed to by timer
   *    to local time in the form of a string. It is equivalent to
   *    asctime(localtime(timer))
   */

  return asctime(localtime(timep));
#else
  return asctime(gmtime(timep));
#endif
}

#endif /* CONFIG_TIME_EXTENDED */