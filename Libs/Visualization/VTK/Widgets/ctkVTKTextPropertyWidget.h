/*=========================================================================

  Library:   CTK

  Copyright (c) 2010  Kitware Inc.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.commontk.org/LICENSE

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=========================================================================*/

#ifndef __ctkVTKTextPropertyWidget_h
#define __ctkVTKTextPropertyWidget_h

// Qt includes
#include <QWidget>

// CTK includes
#include "ctkPimpl.h"
#include "ctkVTKObject.h"
#include "CTKVisualizationVTKWidgetsExport.h"

class ctkVTKTextPropertyWidgetPrivate;
class vtkTextProperty;

class CTK_VISUALIZATION_VTK_WIDGETS_EXPORT ctkVTKTextPropertyWidget : public QWidget
{
  Q_OBJECT;
  QVTK_OBJECT;
  Q_PROPERTY(bool showText READ isTextVisible WRITE setTextVisible);
  Q_PROPERTY(QString text READ text WRITE setText);
  Q_PROPERTY(QString textLabel READ textLabel WRITE setTextLabel);

public:
  /// Constructors
  ctkVTKTextPropertyWidget(QWidget* parentWidget);
  ctkVTKTextPropertyWidget(vtkTextProperty* textProperty, QWidget* parentWidget);
  virtual ~ctkVTKTextPropertyWidget();

  vtkTextProperty* textProperty()const;

  void setTextVisible(bool visible);
  bool isTextVisible()const;

  QString text()const;
  QString textLabel()const;

public slots:
  void setTextProperty(vtkTextProperty* textProperty);
  void setText(const QString& text);
  void setTextLabel(const QString& label);

  void setColor(const QColor& color);
  void setOpacity(double opacity);
  void setFont(const QString& font);
  void setBold(bool enable);
  void setItalic(bool enable);
  void setShadow(bool enable);

signals:
  void textChanged(const QString& text);

protected slots:
  void updateFromTextProperty();

protected:
  QScopedPointer<ctkVTKTextPropertyWidgetPrivate> d_ptr;

private:
  Q_DECLARE_PRIVATE(ctkVTKTextPropertyWidget);
  Q_DISABLE_COPY(ctkVTKTextPropertyWidget);
};

#endif
