import React from 'react'
import styled, {css, keyframes} from 'styled-components'

// inspired from https://css-tricks.com/glitch-effect-text-images-svg/

// const skewDistortion = `transform: skew(${Math.random() * 20 * (Math.random() > 0.5 ? -1 : 1)}deg)`
const noiseAnimationSteps = 20;
const noiseAnimation = keyframes`
  ${
    Array.from({length: noiseAnimationSteps}).map((_, index) => {
      const top =  (Math.random() * 100);
      const bottom=  Math.random() * (101 - top);
      return `
        ${Math.floor( index * 1/20 * 100 )}% {
          clip-path: inset(${top}% 0 ${bottom}% 0);
        }
      `}).join('')
  }
`

const glitchColor1 = 'red'
const glitchColor2 = 'yellow'
const backgroundColor = 'white'
const textColor = 'black'

const Wrapper = styled.div`
  background-color: ${backgroundColor};
  padding-left: 30px;
  padding-right: 30px;
`

const Glitch = styled.h2.attrs(({children}) => ({
  'data-text': children,
}))`
    text-align: center;
    position: relative;
    color: ${textColor};
    background-color: ${backgroundColor};
    font-style: italic;
    font-size: ${props => props.variant === "featured" ? "10rem" : "auto" }

   &::after, &::before {
    content: attr(data-text);
    position: absolute;
    top: 0;
    left: 0;
    width: 100%;
    height: 100%;
  }

  &::before {
    left: 2px;
    text-shadow: -2px 0 ${glitchColor1};
    animation: ${noiseAnimation} 4s infinite linear alternate-reverse;
    background-color: ${backgroundColor};
    color: ${textColor};
  }

  &::after {
     ${props => (props.glitchText1 ? css`content: "${props => props.glitchText1}";` : null )}
    left: -2px;
    text-shadow: 2px 0 ${glitchColor2};
    background-color: ${backgroundColor};
    color: ${textColor};
    animation: ${noiseAnimation} 4s infinite linear alternate-reverse;
  }
`

export const Title = ({ children, ...props }) => {
  return (
    <Wrapper>
      <Glitch {...props}>{children}</Glitch>
    </Wrapper>
  )
}
