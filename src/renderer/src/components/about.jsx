import githubMark from '../assets/github-mark-white.svg'

function About() {
  return (
    <footer>
      <ul className="links">
        <li className="about">hmm...</li>
        <li className="github">
          <a href="https://github.com/yav12/zzz-optimizer" target="_blank" rel="noreferrer">
            <img src={githubMark} alt="GitHub" width={20} height={20} />
          </a>
        </li>
      </ul>
    </footer>
  )
}
export default About
