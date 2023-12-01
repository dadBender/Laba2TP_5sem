const startBtn = document.querySelector('#start')
const screens = document.querySelectorAll('.screen')
const timeList = document.querySelector('#time-list')
const timeEl = document.querySelector('#time')
const board = document.querySelector('#board')
let time = 0
let score = 0
const color =['#BF3030', '#FF4040', '#BF7930', '#007143', '#21825B', '#3D9AD1', '#64A8D1', '#5B2680', '#A767D5', '#2E3983']
const sizeOfColor = color.length-1

startBtn.addEventListener('click', (event)=> {

event.preventDefault()
screens[0].classList.add('up')
})

timeList.addEventListener('click', event=>
{
    if (event.target.classList.contains('time-btn')){
        time = parseInt(event.target.getAttribute('data-time'))
        screens[1].classList.add('up')
        startGame()
    }
})

board.addEventListener('click', event=>
{
    if(event.target.classList.contains('circle')){
        score ++
        event.target.remove()
        createRandomCircle()
    }
})

function startGame() {
    setInterval(decreaseTime, 1000)
    createRandomCircle()
    setTime(time)
}

function decreaseTime(){
    if (time === 0){
        finishGame()
    } else {
    let current = --time
    if (current < 10){
        current = `0${current}`
    }
    setTime(current)}
}
function setTime(value){
    timeEl.innerHTML = `00:${value}`

}
function finishGame(){
    timeEl.parentNode.classList.add('hide')
    board.innerHTML = `<h1>Счет: <span class="primary">${score}</span></h1>`
}

function createRandomCircle() {
    const circle = document.createElement('div')
    const size = getRandomNumber(10,60)
    const {width, height} = board.getBoundingClientRect()
    const x =  getRandomNumber(0, width-size)
    const y = getRandomNumber(0, height-size)
    const colorOfCircle = color[getRandomNumber(0, sizeOfColor)]

    circle.classList.add('circle')
    circle.style.width = `${size}px`
    circle.style.height = `${size}px`
    circle.style.top = `${y}px`
    circle.style.left = `${x}px`
    circle.style.background = `${colorOfCircle}`
    board.append(circle)
}

function getRandomNumber(min, max) {
   return Math.round(Math.random()*(max-min) + min)
}

function winTheGame() {
    function kill(){
    const circle = document.querySelector('.circle')
    if (circle) {
        circle.click()
    }    
}            
    setInterval (kill, 42)                                         
}