//
// TextEditCell.cpp
//
// $Id: //poco/Main/WebWidgets/src/TextEditCell.cpp#2 $
//
// Library: WebWidgets
// Package: Controls
// Module:  TextEditCell
//
// Copyright (c) 2007, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#include "Poco/WebWidgets/TextEditCell.h"


namespace Poco {
namespace WebWidgets {



TextEditCell::TextEditCell(View* pOwner):
	Cell(pOwner, typeid(TextEditCell)),
	_heightInPixel(-1),
	_canGrow(false)
{
}


TextEditCell::TextEditCell(View* pOwner, const std::type_info& type):
	Cell(pOwner, type),
	_heightInPixel(-1),
	_canGrow(false)
{
}


TextEditCell::~TextEditCell()
{
}


void TextEditCell::handleForm(const std::string& field, const std::string& value)
{
	if (value != getString())
	{
		setValue(value);
		textChanged(this);
	}
}


bool TextEditCell::serializeJSON(std::ostream& out, const std::string& name)
{
	out << name << ":";
	if (this->hasValue())
	{
		out << "'" << getFormatter()->format(getValue()) << "'";
	}
	return true;
}


} } // namespace Poco::WebWidgets
