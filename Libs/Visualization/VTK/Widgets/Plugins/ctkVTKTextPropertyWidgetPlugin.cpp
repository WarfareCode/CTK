/*=========================================================================

  Library:   CTK

  Copyright (c) Kitware Inc.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0.txt

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=========================================================================*/

// CTK includes
#include "ctkVTKTextPropertyWidget.h"
#include "ctkVTKTextPropertyWidgetPlugin.h"

//-----------------------------------------------------------------------------
ctkVTKTextPropertyWidgetPlugin::ctkVTKTextPropertyWidgetPlugin(QObject *_parent):QObject(_parent)
{
}

//-----------------------------------------------------------------------------
QWidget *ctkVTKTextPropertyWidgetPlugin::createWidget(QWidget *parentWidget)
{
  ctkVTKTextPropertyWidget* newWidget =
    new ctkVTKTextPropertyWidget(parentWidget);
  return newWidget;
}

//-----------------------------------------------------------------------------
QString ctkVTKTextPropertyWidgetPlugin::domXml() const
{
  return "<widget class=\"ctkVTKTextPropertyWidget\" \
          name=\"VTKTextProperty\">\n"
          "</widget>\n";
}

//-----------------------------------------------------------------------------
QString ctkVTKTextPropertyWidgetPlugin::includeFile() const
{
  return "ctkVTKTextPropertyWidget.h";
}

//-----------------------------------------------------------------------------
bool ctkVTKTextPropertyWidgetPlugin::isContainer() const
{
  return false;
}

//-----------------------------------------------------------------------------
QString ctkVTKTextPropertyWidgetPlugin::name() const
{
  return "ctkVTKTextPropertyWidget";
}
