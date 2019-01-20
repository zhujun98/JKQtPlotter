/*
    Copyright (c) 2008-2019 Jan W. Krieger (<jan@jkrieger.de>)

    

    This software is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License (LGPL) as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License (LGPL) for more details.

    You should have received a copy of the GNU Lesser General Public License (LGPL)
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "jkqtplottertools/jkqtp_imexport.h"
#include "jkqtplotter/jkqtpgraphsbase.h"


#ifndef jkqtpgraphsimpulses_H
#define jkqtpgraphsimpulses_H



/*! \brief This implements an impulse plot with impulses in direction of the X axis (i.e. from y=0 to y=f(x) )
    \ingroup jkqtplotter_barssticks

    \image html plot_impulsesxplots.png
 */
class LIB_EXPORT JKQTPImpulsesHorizontalGraph: public JKQTPXYGraph {
        Q_OBJECT
    public:
        /** \brief class constructor */
        JKQTPImpulsesHorizontalGraph(JKQTBasePlotter* parent=nullptr);
        /** \brief class constructor */
        JKQTPImpulsesHorizontalGraph(JKQTPLotter* parent);

        /** \brief plots the graph to the plotter object specified as parent */
        virtual void draw(JKQTPEnhancedPainter& painter) override;
        /** \brief plots a key marker inside the specified rectangle \a rect */
        virtual void drawKeyMarker(JKQTPEnhancedPainter& painter, QRectF& rect) override;
        /** \brief returns the color to be used for the key label */
        virtual QColor getKeyLabelColor() override;

        /*! \brief sets the property color to the specified \a __value. 
            \details Description of the parameter color is: <BLOCKQUOTE>\copybrief color </BLOCKQUOTE> 
            \see color for more information */ 
        inline virtual void set_color(const QColor & __value)  
        {
            this->color = __value;
        } 
        /*! \brief returns the property color. 
            \details Description of the parameter color is: <BLOCKQUOTE>\copybrief color </BLOCKQUOTE> 
            \see color for more information */ 
        inline virtual QColor get_color() const  
        {
            return this->color; 
        }
        /*! \brief sets the property lineWidth to the specified \a __value. 
            \details Description of the parameter lineWidth is: <BLOCKQUOTE>\copybrief lineWidth </BLOCKQUOTE> 
            \see lineWidth for more information */ 
        inline virtual void set_lineWidth(double __value)  
        {
            this->lineWidth = __value;
        } 
        /*! \brief returns the property lineWidth. 
            \details Description of the parameter lineWidth is: <BLOCKQUOTE>\copybrief lineWidth </BLOCKQUOTE> 
            \see lineWidth for more information */ 
        inline virtual double get_lineWidth() const  
        {
            return this->lineWidth; 
        }
        /*! \brief sets the property baseline to the specified \a __value. 
            \details Description of the parameter baseline is: <BLOCKQUOTE>\copybrief baseline </BLOCKQUOTE> 
            \see baseline for more information */ 
        inline virtual void set_baseline(double __value)  
        {
            this->baseline = __value;
        } 
        /*! \brief returns the property baseline. 
            \details Description of the parameter baseline is: <BLOCKQUOTE>\copybrief baseline </BLOCKQUOTE> 
            \see baseline for more information */ 
        inline virtual double get_baseline() const  
        {
            return this->baseline; 
        }

        /** \brief color of the graph */
        QColor color;
        /** \brief width (pixels) of the lines */
        double lineWidth;

    protected:
        /** \brief which plot style to use from the parent plotter (via JKQTPLotterBase::getPlotStyle() and JKQTPLotterBase::getNextStyle() ) */
        int parentPlotStyle;

        /** \brief baseline of the plot (NOTE: 0 is interpreted as until plot border in log-mode!!!)
         */
        double baseline;
        QPen getPen(JKQTPEnhancedPainter &painter) const;
};



/*! \brief This implements an impulse plot with impulses in direction of the X axis (i.e. from x=0 to x=f(y) )
    \ingroup jkqtplotter_barssticks

    \image html plot_impulsesxerrorsplots.png
 */
class LIB_EXPORT JKQTPImpulsesHorizontalErrorGraph: public JKQTPImpulsesHorizontalGraph, public JKQTPXGraphErrors {
        Q_OBJECT
    public:
        /** \brief class constructor */
        JKQTPImpulsesHorizontalErrorGraph(JKQTBasePlotter* parent=nullptr);
        JKQTPImpulsesHorizontalErrorGraph(JKQTPLotter* parent);
        /** \copydoc JKQTPGraph::usesColumn() */
        virtual bool usesColumn(int c) const override;

    protected:
        /** \brief this function is used to plot error inidcators before plotting the graphs. */
        virtual void drawErrorsAfter(JKQTPEnhancedPainter& painter) override ;

};




/*! \brief This implements an impulse plot with impulses in direction of the Y axis (i.e. from y=0 to y=f(x) )
    \ingroup jkqtplotter_barssticks

    \image html plot_impulsesyplots.png
 */
class LIB_EXPORT JKQTPImpulsesVerticalGraph: public JKQTPImpulsesHorizontalGraph {
        Q_OBJECT
    public:
        /** \brief class constructor */
        JKQTPImpulsesVerticalGraph(JKQTBasePlotter* parent=nullptr);
        /** \brief class constructor */
        JKQTPImpulsesVerticalGraph(JKQTPLotter* parent);

        /** \brief plots the graph to the plotter object specified as parent */
        virtual void draw(JKQTPEnhancedPainter& painter) override;
};



/*! \brief This implements an impulse plot with impulses in direction of the X axis (i.e. from x=0 to x=f(y) )
    \ingroup jkqtplotter_barssticks

    \image html plot_impulsesyerrorsplots.png
 */
class LIB_EXPORT JKQTPImpulsesVerticalErrorGraph: public JKQTPImpulsesVerticalGraph, public JKQTPYGraphErrors {
        Q_OBJECT
    public:
        /** \brief class constructor */
        JKQTPImpulsesVerticalErrorGraph(JKQTBasePlotter* parent=nullptr);
        /** \brief class constructor */
        JKQTPImpulsesVerticalErrorGraph(JKQTPLotter* parent);
        /** \copydoc JKQTPGraph::usesColumn() */
        virtual bool usesColumn(int c) const override;

    protected:
        /** \brief this function is used to plot error inidcators before plotting the graphs. */
        virtual void drawErrorsAfter(JKQTPEnhancedPainter& painter) override ;

};




#endif // jkqtpgraphsimpulses_H
