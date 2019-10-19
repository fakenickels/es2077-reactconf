import React from "react"
import Highlight, { defaultProps } from "prism-react-renderer";
import theme from "prism-react-renderer/themes/nightOwlLight"

export const Highlighter = ({ code, language, currentHighlights = [NaN, NaN], noSurfing }) => 
  <Highlight {...defaultProps} theme={ theme } code={code} language={language}>
    {({ className, style, tokens, getLineProps, getTokenProps }) => (
      <pre className={className} style={style}>
        {tokens.map((line, i) => {
          const { style: prismStyle, ...props } = getLineProps({ line, key: i })
          const style = {
            ...prismStyle,
            opacity: noSurfing || (i+1 >= currentHighlights[0] && i+1 <= currentHighlights[1]) ? 1 : 0.5,
            transition: 'opacity ease-out 0.3s'
          }

          return (
            <div {...props} style={style}>
              {line.map((token, key) => (
                <span {...getTokenProps({ token, key })} />
              ))}
            </div>
          )
        })}
      </pre>
    )}
  </Highlight>

