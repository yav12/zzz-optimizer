import { useFilePicker } from 'use-file-picker'

export default function App() {
  const { openFilePicker, filesContent, loading } = useFilePicker({
    accept: '.txt'
  })

  if (loading) {
    return <div>Loading...</div>
  }

  return (
    <div>
      <a className="filepicker" onClick={() => openFilePicker()}>
        Select files
      </a>
      {filesContent.map((file, index) => (
        <div key={index}>
          <h2>{file.name}</h2>
          <div key={index}>{file.content}</div>
        </div>
      ))}
    </div>
  )
}
