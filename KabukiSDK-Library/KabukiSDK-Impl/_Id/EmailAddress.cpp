﻿/** Kabuki Software Development Kit
    @file    /.../KabukiSDK-Impl/_Id/EmailAddress.cpp
    @author  Cale McCollough <cale.mccollough@gmail.com>
    @license Copyright (C) 2016 [Cale McCollough](calemccollough.github.io)

                            All right reserved (R).

        Licensed under the Apache License, Version 2.0 (the "License"); you may
        not use this file except in compliance with the License. You may obtain
        a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

        Unless required by applicable law or agreed to in writing, software
        distributed under the License is distributed on an "AS IS" BASIS,
        WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
        See the License for the specific language governing permissions and
        limitations under the License.
*/

#include <_Id/EmailAddress.hpp>

namespace _Id {

EmailAddress::EmailAddress (const char* S)
{

}

/** Sets the email address to a string. */
bool EmailAddress::getEmailAddress (const char* S)
{
    invalid = false;
    if (String.IsNullOrEmpty (S)) return false;

    /// Use IdnMapping class to convert Unicode domain names.
    try
    {
        S = Regex.Replace (a, @" (@) (.+)$", this.DomainMapper, RegexOptions.None, TimeSpan.FromMilliseconds (200));
    }
    catch (RegexMatchTimeoutException) { return false; }

    if (invalid) return false;

    // Return true if a is in valid e-mail format.
    try
    {
        return Regex.IsMatch (a,
            @"^ (? ("") ("".+? (?<!\\)""@)| (([0-9a-z] ((\. (?!\.))|[-!#\$%&'\*\+/=\?\^`\{\}\|~\w])*) (?<=[0-9a-z])@))" +
            @" (? (\[) (\[ (\d{1,3}\.){3}\d{1,3}\])| (([0-9a-z][-\w]*[0-9a-z]*\.)+[a-z0-9][\-a-z0-9]{0,22}[a-z0-9]))$",
            RegexOptions.IgnoreCase, TimeSpan.FromMilliseconds (250));
    }
    catch (RegexMatchTimeoutException) { return false; }
}

char* EmailAddress::getEmailAddress () { return address; }

void EmailAddress::getEmailAddress (const char* S) {address = S;}

string EmailAddress::domainMapper (Match match)
{
    // IdnMapping class with default property values.
    IdnMapping idn = new IdnMapping ();

    string domainName = match.Groups[2].Value;
    try
    {
        domainName = idn.GetAscii (domainName);
    }
    catch (ArgumentException) {
        invalid = true;
    }
    return match.Groups[1].getValue () + domainName;
}

}   //< namespace _Id
